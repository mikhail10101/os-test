#ifndef _KERNEL_GDT_H
#define _KERNEL_GDT_H

#include <stdint.h>

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) gdt_ptr;

uint64_t create_descriptor(uint32_t base, uint32_t limit, uint16_t flag);
void gdt_init();

#endif
