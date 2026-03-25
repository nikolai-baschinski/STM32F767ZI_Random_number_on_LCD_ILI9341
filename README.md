This software displays a RNG generated random number on the Waveshare ILI9341 LCD by STM32F767ZI (dev board) bare metal (no HAL) using the CubeIDE.

![](/Doc/IMG_5004_small.jpg)

Connections (https://os.mbed.com/platforms/ST-Nucleo-F767ZI/)


| LCD      | Port     | Function     |
|----------|----------|------------- |
| VCC      | 3,3V     | Vcc          |
| GND      | GND      | GND          |
| DIN      | PA7      | SPI1_MOSI    |
| CLK      | PA5      | SPI1_CLK     |
| CS       | PB6      | Chip Select  |
| DC       | PA0      | Data/Command |
| RST      | PB9      | Reset        |
| BL       | -        | Backlight    |

The business logic is very simple. If the user button (B1) is pushed, a random number is generated using the RNG module of the STM32F7 and is sent to the LCD via SPI.

```
void cyclic_Application(struct ProcessImage* p_pi)
{
  if (GPIO_button_pushed()) {
    uint16_t random_number = RNG_get_random_number();
    LCD_print_random_number(random_number);
  }
}
```

Hardware:

LCD: https://www.waveshare.com/wiki/2.4inch_LCD_Module?srsltid=AfmBOoqtv3bq-mZfPtsi2BxiewwQnIkomXrloIzpVwGw_HnrOcmvQZar

Nucleo-STM32767ZI: https://www.st.com/en/evaluation-tools/nucleo-f767zi.html
