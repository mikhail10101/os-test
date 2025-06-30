#include <kernel/idt.h>

__attribute__((aligned(0x10)))
static idt_entry_t idt[256];

static idtr_t idtr;


// Default exception handler
void exception_handler() {
    __asm__ volatile ("cli; hlt");
}

// Provided by the OSDev wiki
void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    idt_entry_t* descriptor = &idt[vector];

    descriptor->isr_low        = (uint32_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08;
    descriptor->attributes     = flags;
    descriptor->isr_high       = (uint32_t)isr >> 16;
    descriptor->reserved       = 0;
}


static bool vectors[IDT_MAX_DESCRIPTORS];

extern void* isr_stub_table[];

void idt_init() {
    // Initialize the idtr_t with the size and base address of the idt_entry_t
    idtr.base = (uintptr_t)&idt[0];
    idtr.limit = (uint16_t)sizeof(idt_entry_t) * IDT_MAX_DESCRIPTORS - 1;

    // Initialize the idt_entry_t
    for (uint8_t vector = 0; vector < 32; vector++) {
        idt_set_descriptor(vector, isr_stub_table[vector], 0x8E);
        vectors[vector] = true;
    }

    // Load interrupt descriptor table
    __asm__ volatile ("lidt %0" : : "m"(idtr));

    // Set interrupt flag which enables hardware interrupts
    __asm__ volatile ("sti");
}