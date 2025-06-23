#include <stdio.h>
#include <stdlib.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>

typedef struct {
	int flags;
	int mem_lower;
	int mem_upper;
} __attribute__((packed)) multiboot_info_t;

void kernel_main(multiboot_info_t* mbi) {
	terminal_initialize();

	// char buf[200];
	// printf("%s\n", itoa(mbi->mem_lower, buf, 10));

	setupGDT();
	
	printf("GDT is working!");
}
