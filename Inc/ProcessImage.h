// The process image contains data of the process
// There can't exist loose data- Each data belongs logically to a module
#ifndef PROCESSIMAGE_H_
#define PROCESSIMAGE_H_

#include <stdint.h>
#include "GPIO.h"

struct ProcessImage {
  uint8_t print_on_lcd_flag;
  uint32_t cntr_10ms;
  uint32_t random_number;
  struct GPIO gpio;
};

#endif /* PROCESSIMAGE_H_ */
