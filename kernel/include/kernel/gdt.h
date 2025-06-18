#ifndef _KERNEL_GDT_H
#define _KERNEL_GDT_H

#include <stdint.h>

uint64_t create_descriptor(uint32_t base, uint32_t limit, uint16_t flag);
int setupGDT();

#endif
