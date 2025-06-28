#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/mem.h>

typedef struct {
	uint32_t flags;
	uint32_t mem_lower;
	uint32_t mem_upper;
	uint32_t boot_device;
	uint32_t cmdline;
	uint32_t mods_count;
	uint32_t mods_addr;
} __attribute__((packed)) multiboot_info_t;

void kernel_main(multiboot_info_t* mbi) {
	gdt_init();
	idt_init();
	
	terminal_initialize();
	printf("Before page memory allocation!\n");

	uint32_t mod1 = *(uint32_t*)(mbi->mods_addr + 4);
	uint32_t physicalAllocStart = (mod1 + 0xFFF) & ~(0xFFF);
	// char buf[200];
	// printf("%s\n", itoa(mbi->mem_lower, buf, 10));

	initMem(physicalAllocStart, mbi->mem_upper * 1024);
	
	printf("Working!");
}
