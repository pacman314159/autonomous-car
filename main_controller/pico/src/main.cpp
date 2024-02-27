#include "pico/stdlib.h"
#include"hardware/irq.h"
#include"hardware/timer.h"
#include"hardware/gpio.h"
#include"hardware/i2c.h"
#include "stdio.h"

#include "../include/arduino_i2c_transmission.h"
#include "../include/receiver.h"
#include "../include/wheels.h"

const int PRO_MINI_I2C_ADDR = 0x31;
const int I2C_SDA = 20;
const int I2C_SCL = 21;
const int LEFT_WHEEL_PWM_GPIO = 14;
const int RIGHT_WHEEL_PWM_GPIO = 15;
//                             1   2   3   4
int L298N_DRIVER_IN_GPIO[4] = {13, 12, 11, 10};

int RX_GPIOS[4] = {6, 7, 8, 9};
uint32_t rx_pulse_len[4];

uint32_t tof_data[5];

signed main(){
  stdio_init_all();
  gpio_init(25); gpio_set_dir(25, GPIO_OUT);
  sio_hw->gpio_set |= 1LL << 25;

  rx_init(RX_GPIOS, 4);

  i2c_protocol_arduino_init(i2c_default, 400000, I2C_SDA, I2C_SCL);

  wheels_init(
      LEFT_WHEEL_PWM_GPIO,
      RIGHT_WHEEL_PWM_GPIO,
      TIMER_IRQ_0,
      TIMER_IRQ_1,
      L298N_DRIVER_IN_GPIO
      );

  while(true){
    // rx_read(rx_pulse_len, 4);

    // tofs_read(tof_data, 5, i2c_default, PRO_MINI_I2C_ADDR);

    //create_rise_edge();
    //handle_fall_edge();

  }
}
