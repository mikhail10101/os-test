# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot, "ax"
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.long 0
.long 0
.long 0
.long 0

.long 0
.long 800
.long 600
.long 32

# Reserve a stack for the initial thread.
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The kernel entry point.
.section .multiboot.text, "ax"
.global _start
_start:
	# Setup paging.
	movl $initial_page_dir, %eax
	subl $0xC0000000, %eax
	movl %eax, %cr3

	movl %cr4, %ecx 
	orl $0x10, %ecx 
	movl %ecx, %cr4

	movl %cr0, %ecx
	orl $0x80000000, %ecx 
	movl %ecx, %cr0 

	jmp higher_half
// .size _start, . - _start

.section .text
higher_half:
	movl $stack_top, %esp	# Set stack pointer
	XOR %ebp, %ebp			# Set base pointer to 0
	call _init				# Call global constructors
	pushl %ebx				# Push multiboot info onto the stack
	call kernel_main		

	# Hang if kernel_main unexpectedly returns.
	cli
1:	hlt
	jmp 1b

# Data section
.section .data 
.align 4096
.set PDE_ENTRY, 0b10000011
.global initial_page_dir
initial_page_dir:
	# 768 entries
	.long PDE_ENTRY
	.rept 767
		.long 0
	.endr

	# 256 entries reserved for kernel
	.long (0 << 22) | PDE_ENTRY
	.long (1 << 22) | PDE_ENTRY
	.long (2 << 22) | PDE_ENTRY
	.long (3 << 22) | PDE_ENTRY
	.rept 252
		.long 0
	.endr

