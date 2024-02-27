#ifndef WHEELS_H
#define WHEELS_H

#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"

int l_wheel_alarm_num, l_wheel_timer_irq;
int r_wheel_alarm_num, r_wheel_timer_irq;
int gpio_of_driver_in[5];

int l_wheel_pwm_gpio, r_wheel_pwm_gpio;

static void alarm_irq_left(){
  sio_hw->gpio_clr |= (1LL << l_wheel_pwm_gpio); //pull pin down
  hw_clear_bits(&timer_hw->intr, 1u <<l_wheel_alarm_num);
}

static void alarm_irq_right(){
  sio_hw->gpio_clr |= (1LL << r_wheel_pwm_gpio); //pull pin down
  hw_clear_bits(&timer_hw->intr, 1u << r_wheel_alarm_num);
}

void wheels_init(int left_wheel_pwm_pin, int right_wheel_pwm_pin, int left_wheel_timer_irq, int right_wheel_timer_irq, int *motor_driver_IN_gpios){
  l_wheel_pwm_gpio = left_wheel_pwm_pin;
  l_wheel_timer_irq = left_wheel_timer_irq;
  l_wheel_alarm_num = left_wheel_timer_irq;
  gpio_init(l_wheel_pwm_gpio); gpio_set_dir(l_wheel_pwm_gpio, GPIO_OUT);
  irq_set_exclusive_handler(l_wheel_timer_irq, alarm_irq_left);
  irq_set_enabled(l_wheel_timer_irq, true);

  r_wheel_pwm_gpio = right_wheel_pwm_pin;
  r_wheel_timer_irq = right_wheel_timer_irq;
  r_wheel_alarm_num = right_wheel_timer_irq;
  gpio_init(r_wheel_pwm_gpio); gpio_set_dir(r_wheel_pwm_gpio, GPIO_OUT);
  irq_set_exclusive_handler(r_wheel_timer_irq, alarm_irq_right);
  irq_set_enabled(r_wheel_timer_irq, true);

  //set spinning direction
  for(int i = 1; i <= 4; i++){
    gpio_of_driver_in[i] = motor_driver_IN_gpios[i-1];
    gpio_init(gpio_of_driver_in[i]);
    gpio_set_dir(gpio_of_driver_in[i], GPIO_OUT);
  }
  sio_hw->gpio_set |= (1LL << gpio_of_driver_in[2]) | (1LL << gpio_of_driver_in[4]);
  sio_hw->gpio_clr |= (1LL << gpio_of_driver_in[1]) | (1LL << gpio_of_driver_in[3]);
  //reverse
  // sio_hw->gpio_set |= (1LL << gpio_of_driver_in[1]) | (1LL << gpio_of_driver_in[3]);
  // sio_hw->gpio_clr |= (1LL << gpio_of_driver_in[2]) | (1LL << gpio_of_driver_in[4]);
}

void wheels_create_pwm(int pulse_length_left, int pulse_length_right){
  sio_hw->gpio_set |= ((1LL << l_wheel_pwm_gpio) | (1LL << r_wheel_pwm_gpio)) ;//pull up pins

  hw_set_bits(
      &timer_hw->inte,
      (1u << r_wheel_alarm_num) | (1u <<l_wheel_alarm_num)
      );

  uint64_t current_time = timer_hw->timerawl;
  uint64_t target_time_left = current_time + pulse_length_left;
  uint64_t target_time_right = current_time + pulse_length_right;

  timer_hw->alarm[l_wheel_alarm_num] = (uint32_t)target_time_left;
  timer_hw->alarm[r_wheel_alarm_num] = (uint32_t)target_time_right;
}

#endif
