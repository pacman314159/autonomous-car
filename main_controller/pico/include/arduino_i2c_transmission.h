#ifndef ARDUINO_I2C_TRANSMISSION_H
#define ARDUINO_I2C_TRANSMISSION_H

#include"hardware/i2c.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "stdio.h"

void i2c_protocol_arduino_init(i2c_inst_t *i2c, uint32_t sda, uint32_t scl);
void tofs_read(uint32_t *distances, int num_sensors, i2c_inst_t *i2c, uint32_t address);

#endif
