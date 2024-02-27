#include "../include/arduino_i2c_transmission.h"

void i2c_protocol_arduino_init(i2c_inst_t *i2c, uint32_t sda, uint32_t scl){
  i2c_init(i2c_default, 400000);
  gpio_init(20); gpio_init(21);
  gpio_set_function(20, GPIO_FUNC_I2C); gpio_pull_up(20);
  gpio_set_function(21, GPIO_FUNC_I2C); gpio_pull_up(21);
}

void tofs_read(uint32_t *distances, int num_sensors, i2c_inst_t *i2c, uint32_t address){
  uint8_t buffer[4 * num_sensors];
  uint32_t merged_bytes;
  i2c_read_blocking(i2c, address, buffer, 20, false);

  for(int i = 0; i < num_sensors; i++){
    merged_bytes = (uint32_t)(buffer[i*4] << 24) | (uint32_t)(buffer[i*4+1] << 16) | (uint32_t)(buffer[i*4+2] << 8) | buffer[i*4+3];
    distances[i] = *(float*)&merged_bytes;
  }
}
