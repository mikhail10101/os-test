#include <stdio.h>
#include <stdlib.h>

#include <kernel/tty.h>

void kernel_main(int rec) {
	terminal_initialize();

	char buff[200];
	printf("%s", itoa(rec, buff));
}
