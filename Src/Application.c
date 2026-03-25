#include "Application.h"
#include "GPIO.h"
#include "RNG.h"
#include "lcd.h"

void cyclic_Application(struct ProcessImage* p_pi)
{
  if (GPIO_button_pushed()) {
    uint16_t random_number = RNG_get_random_number();
    LCD_print_random_number(random_number);
  }
}
