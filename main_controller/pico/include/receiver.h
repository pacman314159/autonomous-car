#ifndef RECEIVER_H
#define RECEIVER_H

#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"

#include"stdio.h"

void rx_init(int gpios[], int num_channels);
void rx_read(uint32_t *pulse_len_channel, int num_channels);

#endif
