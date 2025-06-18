#include <stdio.h>
#include <stdlib.h>

#include <kernel/tty.h>

typedef struct {
	int flags;
	int mem_lower;
	int mem_upper;
} __attribute__((packed)) multiboot_info_t;

void kernel_main(multiboot_info_t* mbi) {
	terminal_initialize();

	char buff[200];
	printf("%s", itoa(mbi->mem_lower, buff));
}
