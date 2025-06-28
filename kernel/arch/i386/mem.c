#include <kernel/mem.h>

#include <string.h>

static uint32_t pageFrameMin;
static uint32_t pageFrameMax;
static uint32_t totalAlloc;

#define NUM_PAGES_DIRS 256
#define NUM_PAGE_FRAMES (0x100000000 / PAGE_SIZE / 8)
uint8_t physicalMemoryBitmap[NUM_PAGE_FRAMES / 8]; // Do dynamically as a bit array

static uint32_t pageDirs[NUM_PAGES_DIRS][1024] __attribute__((aligned(PAGE_SIZE)));
static uint8_t pageDirUsed[NUM_PAGES_DIRS];

void initMem(uint32_t physicalAllocStart, uint32_t memHigh) {
    initial_page_dir[0] = 0;
    invalidate(0);
    initial_page_dir[1023] = ((uint32_t) initial_page_dir - KERNEL_START) | PAGE_FLAG_PRESENT | PAGE_FLAG_WRITE;
    invalidate(0xFFFFF000); 

    pmm_init(physicalAllocStart, memHigh);
    memset(pageDirs, 0, PAGE_SIZE * NUM_PAGES_DIRS);
    memset(pageDirUsed, 0, NUM_PAGES_DIRS);
}

void pmm_init(uint32_t memLow, uint32_t memHigh) {
    pageFrameMin = CEIL_DIV(memLow, PAGE_SIZE);
    pageFrameMax = memHigh / PAGE_SIZE;
    totalAlloc = 0;

    memset(physicalMemoryBitmap, 0, sizeof(physicalMemoryBitmap));
}

void invalidate(uint32_t vaddr) {
    asm volatile("invlpg %0" :: "m"(vaddr));
}




