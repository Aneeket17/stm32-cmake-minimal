#include <stdint.h>

volatile uint32_t placeholder_counter;

static int some_number = 42;

int main(void)
{
    while (1)
    {
        placeholder_counter++;
        while(some_number < 100)
        {
            some_number++;
        }
    }
}