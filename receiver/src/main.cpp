#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"

#include "pico/time.h"
#include "stdio.h"
#include "../include/receiver.h"

int rx_gpios[4] = {6, 7, 8, 9};
uint32_t pulse_len_channel[4];

signed main(){
  stdio_init_all();
  gpio_init(25); gpio_set_dir(25, GPIO_OUT);
  sleep_ms(1000);
  sio_hw->gpio_set |= (1LL << 25);

  rx_init(rx_gpios, 4);

  while(true){
    rx_read(pulse_len_channel, 4);
    printf("%d ", pulse_len_channel[0]);
    printf("%d ", pulse_len_channel[1]);
    printf("%d ", pulse_len_channel[2]);
    printf("%d \n", pulse_len_channel[3]);
    sleep_ms(50);
  }
}

