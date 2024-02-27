#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"

#include <stdio.h>

signed main(void){
  stdio_init_all();
  gpio_init(25);
  gpio_set_dir(25, GPIO_OUT);
  sio_hw->gpio_set = (1LL << 25);

  uint32_t prevTime;
  while(true){
    prevTime = time_us_32();
    sio_hw->gpio_set |= (1LL << 25);
    while(time_us_32() - prevTime < 1000000);

    prevTime = time_us_32();
    sio_hw->gpio_clr |= (1LL << 25);
    while(time_us_32() - prevTime < 1000000);
  }
}
