#ifndef MEM_C
#define MEM_C

#define KERNEL_START 0xC0000000
#define PAGE_FLAG_PRESENT (1 << 0)
#define PAGE_FLAG_WRITE (1 << 1)

#define PAGE_SIZE 0x1000

#define CEIL_DIV(a,b) (((a + b) - 1) / b)

#include <stdint.h>

extern uint32_t initial_page_dir[1024];
void initMem(uint32_t memHigh, uint32_t physicalAllocStart);
void pmm_init(uint32_t memLow, uint32_t memHigh);
void invalidate(uint32_t vaddr);

#endif