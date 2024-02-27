#include "../include/receiver.h"

#include "hardware/gpio.h"
#include"stdio.h"
#include "pico/stdlib.h"

const int MAX_GPIO_PICO_BOARD = 28;
uint32_t rise_edge_gpio[MAX_GPIO_PICO_BOARD], pulse_length_gpio[MAX_GPIO_PICO_BOARD];
int gpio_of_channel[4];

void gpio_callback(uint gpio, uint32_t events){
  switch(events){
    case GPIO_IRQ_EDGE_RISE:
      rise_edge_gpio[gpio] = time_us_32();
      break;
    case GPIO_IRQ_EDGE_FALL:
      pulse_length_gpio[gpio] = time_us_32() - rise_edge_gpio[gpio];
      break;
  }
}

void rx_init(int gpios[], int num_channels){
  for(int i = 0; i < num_channels; i++){
    gpio_of_channel[i] = gpios[i];
    gpio_init(gpios[i]);
    gpio_set_dir(gpios[i], GPIO_IN);
    gpio_pull_down(gpios[i]);
    gpio_set_irq_enabled_with_callback(gpios[i], GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
  }
}

void rx_read(uint32_t *pulse_len_channel, int num_channels){
  for(int i = 0; i < num_channels; i++)
    pulse_len_channel[i] = pulse_length_gpio[gpio_of_channel[i]];
}
