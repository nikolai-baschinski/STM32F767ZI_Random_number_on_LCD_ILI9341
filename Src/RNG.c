#include "RNG.h"
#include "stm32f767xx.h"

uint32_t getRandomNumberInRange( uint32_t Min, uint32_t Max )
{
  uint32_t randomNumber = RNG->DR;
  return ( (randomNumber % ((Max-Min)+1)) + Min );
}

void init_RNG()
{
  RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN;  // enable RNG Clock
  RNG->CR |= RNG_CR_RNGEN;            // enable RNG
  while (!(RNG->SR & RNG_SR_DRDY));   // wait till the NRG is ready
}

void cyclic_RNG()
{
  // Erase any errors
  if(RNG->SR & (RNG_SR_SEIS | RNG_SR_CEIS)) {
    RNG->SR = 0;
  }
}

uint16_t RNG_get_random_number()
{
  return (uint16_t)getRandomNumberInRange(0, 1000);
}
