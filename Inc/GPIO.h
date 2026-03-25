#ifndef GPIO_H_
#define GPIO_H_

struct ProcessImage;

struct GPIO {
  uint8_t button_pushed;
  uint8_t button_pushed_memory;
  uint8_t debounce_counter;
};

void init_GPIO(struct GPIO* p_gpio);
void cyclic_GPIO(struct ProcessImage* p_pi);
uint8_t GPIO_button_pushed();

#endif /* GPIO_H_ */
