// Nikolai Baschinski
// Reading temperature, air pressure and humidity from BME280
// and showing it on the ILI93411 LCD

#include "main.h"

struct ProcessImage pi={0};

int main(void)
{
  init_FPU();
  init_PLL();
  init_GPIO(&pi.gpio);
  init_TIM();
  init_SPI();
  init_RNG();
  init_LCD(&pi);
  init_NVIC();

  for(;;) {
    cyclic_LCD(&pi);
  }
}

void TIM2_IRQHandler(void)
{
  if(TIM2->SR & TIM_SR_UIF) {
    TIM2->SR &= ~TIM_SR_UIF; // reset UIF bit in the status register of the timer

    cyclic_GPIO(&pi);
    cyclic_RNG();
    cyclic_Application(&pi);

    pi.cntr_10ms++;
  }
}
