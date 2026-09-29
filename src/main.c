#include <stdint.h>

volatile uint32_t placeholder_counter;

int main(void)
{
    while (1)
    {
        placeholder_counter++;
    }
}