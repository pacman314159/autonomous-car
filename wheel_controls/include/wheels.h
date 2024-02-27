#ifndef WHEELS_H
#define WHEELS_H

#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"

const int L_WHEEL_ALARM_NUM = 0,
          L_WHEEL_TIMER_IRQ = 0;
const int R_WHEEL_ALARM_NUM = 1,
          R_WHEEL_TIMER_IRQ = 1;

int left_wheel_pwm_pin, right_wheel_pwm_pin;

static void alarm_irq_left(){
  sio_hw->gpio_clr |= (1LL << left_wheel_pwm_pin); //pull pin down
  hw_clear_bits(&timer_hw->intr, 1u << L_WHEEL_ALARM_NUM);
}

static void alarm_irq_right(){
  sio_hw->gpio_clr |= (1LL << right_wheel_pwm_pin); //pull pin down
  hw_clear_bits(&timer_hw->intr, 1u << R_WHEEL_ALARM_NUM);
}

void init_wheels(int l_wheel_pwm_pin, int r_wheel_pwm_pin){
  left_wheel_pwm_pin = l_wheel_pwm_pin;
  right_wheel_pwm_pin = r_wheel_pwm_pin;

  gpio_init(left_wheel_pwm_pin); gpio_set_dir(left_wheel_pwm_pin, GPIO_OUT);
  gpio_init(right_wheel_pwm_pin); gpio_set_dir(right_wheel_pwm_pin, GPIO_OUT);

  irq_set_exclusive_handler(L_WHEEL_TIMER_IRQ, alarm_irq_left);
  irq_set_exclusive_handler(R_WHEEL_TIMER_IRQ, alarm_irq_right);

  irq_set_enabled(L_WHEEL_TIMER_IRQ, true);
  irq_set_enabled(R_WHEEL_TIMER_IRQ, true);
}

void create_pwm_2_wheels(int pulse_length_left, int pulse_length_right){

  hw_set_bits(
      &timer_hw->inte,
      (1u << R_WHEEL_ALARM_NUM) | (1u << L_WHEEL_ALARM_NUM)
      );

  uint64_t current_time = timer_hw->timerawl;
  uint64_t target_time_left = current_time + pulse_length_left;
  uint64_t target_time_right = current_time + pulse_length_right;

  timer_hw->alarm[L_WHEEL_ALARM_NUM] = (uint32_t)target_time_left;
  timer_hw->alarm[R_WHEEL_ALARM_NUM] = (uint32_t)target_time_right;

}

#endif

// namespace left_wheel{
//   static void alarm_irq(){
//     sio_hw->gpio_clr |= (1LL << left_wheel_pwm_pin); //pull pin down
//     hw_clear_bits(&timer_hw->intr, 1u << L_WHEEL_ALARM_NUM);
//   }
//   void create_pwm(uint32_t pulse_length_us){
//     hw_set_bits(&timer_hw->inte, 1u << L_WHEEL_ALARM_NUM);
//     irq_set_exclusive_handler(L_WHEEL_TIMER_IRQ, alarm_irq);
//     irq_set_enabled(L_WHEEL_TIMER_IRQ, true);
//     uint64_t time_target = timer_hw->timerawl + pulse_length_us;
//     timer_hw->alarm[L_WHEEL_ALARM_NUM] = (uint32_t)time_target;
//   }
// }
// namespace right_wheel{
//   static void alarm_irq(){
//     sio_hw->gpio_clr |= (1LL << right_wheel_pwm_pin); //pull pin down
//     hw_clear_bits(&timer_hw->intr, 1u << R_WHEEL_ALARM_NUM);
//   }
//   void create_pwm(uint32_t pulse_length_us){
//     hw_set_bits(&timer_hw->inte, 1u << R_WHEEL_ALARM_NUM);
//     irq_set_exclusive_handler(R_WHEEL_TIMER_IRQ, alarm_irq);
//     irq_set_enabled(R_WHEEL_TIMER_IRQ, true);
//     uint64_t time_target = timer_hw->timerawl + pulse_length_us;
//     timer_hw->alarm[R_WHEEL_ALARM_NUM] = (uint32_t)time_target;
//   }
// }
