#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"

#include "pico/time.h"
#include "stdio.h"

#include "../include/wheels.h"
#include "../include/receiver.h"

int L_WHEEL_PWM_GPIO = 14,
    R_WHEEL_PWM_GPIO = 15;
int RX_GPIOS[4] = {6, 7, 8, 9};

uint32_t pulse_len_channel[4];

signed main(){
  stdio_init_all();
  gpio_init(25); gpio_set_dir(25, GPIO_OUT);
  sleep_ms(1000);
  sio_hw->gpio_set |= (1LL << 25);

  rx_init(RX_GPIOS, 4);

  while(true){
    rx_read(pulse_len_channel, 4);
    create_rise_edge();
    handle_interrupt_fall_edge(pulse_len_channel[2], pulse_len_channel[2]);
    sleep_ms(2);
  }
}

