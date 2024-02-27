#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "hardware/i2c.h"

#include "stdio.h"

const int PRO_MINI_I2C_ADDR = 0x31;

uint8_t buffer[4];
uint32_t merged_bytes;

signed main(){
  stdio_init_all();
  gpio_init(25);
  gpio_set_dir(25, GPIO_OUT);
  sio_hw->gpio_set |= 1LL << 25;

  i2c_init(i2c_default, (int)4e5);
  gpio_init(20); gpio_init(21);
  gpio_set_function(20, GPIO_FUNC_I2C); gpio_pull_up(20);
  gpio_set_function(21, GPIO_FUNC_I2C); gpio_pull_up(21);

  while(true){
    i2c_read_blocking(i2c_default, PRO_MINI_I2C_ADDR, buffer, 4, false);
    merged_bytes = (uint32_t)(buffer[0] << 24) | (uint32_t)(buffer[1] << 16) | (uint32_t)(buffer[2] << 8) | buffer[3];
    float distance = *(float*)&merged_bytes;
    printf("%4.5f\n", distance);
    sleep_ms(200);
  }
}

