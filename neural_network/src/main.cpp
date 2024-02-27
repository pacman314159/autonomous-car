#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"

#include <stdio.h>

#include "../include/neural_network.h"

signed main(void){
  stdio_init_all();
  gpio_init(25);
  gpio_set_dir(25, GPIO_OUT);
  sio_hw->gpio_set = (1LL << 25);

  std::vector<uint32_t> topology = {5, 4, 3, 2};
  sp::SimpleNeuralNetwork nn(topology);
  std::vector<float> input = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
  nn.feedForward(input);
  std::vector<float> predictions = nn.getPredictions();

  uint32_t prevTime;
  while(true){
    prevTime = time_us_32();
    sio_hw->gpio_set |= (1LL << 25);
    while(time_us_32() - prevTime < (uint32_t)1e6);

    prevTime = time_us_32();
    sio_hw->gpio_clr |= (1LL << 25);
    while(time_us_32() - prevTime < (uint32_t)1e6);
  }
}
