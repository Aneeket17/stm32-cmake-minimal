#include <stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t *)0x40023830U)
#define GPIOA_MODER (*(volatile uint32_t *)0x40020000U)
#define GPIOA_BSRR  (*(volatile uint32_t *)0x40020018U)
#define GPIOA_OSPEEDR (*(volatile uint32_t *)0x40020008U)
#define GPIOA_ODR (*(volatile uint32_t *)0x40020014U)

void toggle(void)
{
	RCC_AHB1ENR |= (1 << 0);

	GPIOA_MODER &= ~(3 << 10);
	GPIOA_MODER |= (1 << 10); // Set PA5 as output

    GPIOA_OSPEEDR &= ~(3 << 10);
    GPIOA_OSPEEDR |= (2 << 10); // Set PA5 speed to high

	while (1)
	{
		GPIOA_ODR ^= (1 << 5); // Toggle PA5
		for (volatile uint32_t delay = 0; delay < 1000000U; delay++)
		{
		}
	}
}
