#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void Reset_Handler(void);
void Default_Handler(void);
int main(void);

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));

typedef struct
{
    uint32_t *initial_stack_pointer;
    void (*reset_handler)(void);
    void (*nmi_handler)(void);
    void (*hard_fault_handler)(void);
} vector_table_t;

__attribute__((section(".isr_vector")))
const vector_table_t vector_table = {
    &_estack,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
};

void Reset_Handler(void)
{
    uint32_t *source = &_sidata;
    uint32_t *destination = &_sdata;

    while (destination < &_edata)
    {
        *destination++ = *source++;
    }

    destination = &_sbss;

    while (destination < &_ebss)
    {
        *destination++ = 0;
    }

    main();

    while (1)
    {
    }
}

void Default_Handler(void)
{
    while (1)
    {
    }
}