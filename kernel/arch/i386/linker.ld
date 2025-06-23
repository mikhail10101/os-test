ENTRY(_start)
SECTIONS
{
	/* Begin putting sections at 1 MiB, a conventional place for kernels to be
	   loaded at by the bootloader. */
	. = 1M;

	_kernel_start = .;

	.multiboot ALIGN(4K) : {
		*(.multiboot)
		*(.multiboot.text)
	}

	. += 0xC0000000;

	.text ALIGN(4K) : AT(ADDR(.text) - 0xC0000000)
	{
		*(.text)
	}

	/* Read-only data. */
	.rodata ALIGN(4K) : AT(ADDR(.rodata) - 0xC0000000)
	{
		*(.rodata)
	}

	/* Read-write data (initialized) */
	.data ALIGN(4K) : AT(ADDR(.data) - 0xC0000000)
	{
		*(.data)
	}

	/* Read-write data (uninitialized) and stack */
	.bss ALIGN(4K) : AT(ADDR(.bss) - 0xC0000000)
	{
		*(COMMON)
		*(.bss)
	}

	_kernel_end = .;
}
