#include "stm32f767xx.h"
#include "SPI.h"

// For the ILI9341 LCD
void init_SPI1()
{
  RCC->APB2ENR |= RCC_APB2ENR_SPI1EN; // Enable SP1

  // CPOL and CPHA is 0 by default (SPI mode 0)

  SPI1->CR1 |= (3<<3); // divide SYSCLK by

  // MSB comes first, default setting

  SPI1->CR1 |= SPI_CR1_SSM; // Enable software slave management
  SPI1->CR1 |= SPI_CR1_SSI; // Set internal slave select to 1

  // Full-duplex, RXONLY-Bit is default 0

  SPI1->CR1 |= SPI_CR1_MSTR; // Set master mode

  SPI1->CR2 |= (3<<8); // 8 bits data

  SPI1->CR1 |= (1<<6); // Enable SPI
}

void init_SPI()
{
  init_SPI1();
}
