#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"

#include<stdio.h>
#include "../include/wheels.h"

const int L_WHEEL_PWM_PIN = 14,
          R_WHEEL_PWM_PIN = 15;

signed main(void){
  stdio_init_all();
  gpio_init(25); gpio_set_dir(25, GPIO_OUT);
  sio_hw->gpio_set |= (1LL << 25);

  init_wheels(L_WHEEL_PWM_PIN, R_WHEEL_PWM_PIN);

  while(true){
    sio_hw->gpio_set |= ((1LL << R_WHEEL_PWM_PIN) | (1LL << L_WHEEL_PWM_PIN)) ;//pull up pins
    create_pwm_2_wheels(500, 1000);
    //replicate code running below
    sleep_ms(2);
  }
}
