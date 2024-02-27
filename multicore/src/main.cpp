#include "hardware/gpio.h"
#include "hardware/regs/intctrl.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "pico/platform.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"

#include "stdio.h"

void core1_interrupt_handler(){
  //multicore_fifo_pop_blocking();
}

void core1_entry(){

  multicore_fifo_clear_irq();
  irq_set_exclusive_handler(SIO_IRQ_PROC1, core1_interrupt_handler);
  irq_set_enabled(SIO_IRQ_PROC1, true);

  while(true) tight_loop_contents();
}

signed main(){
  stdio_init_all();
  gpio_init(25); gpio_set_dir(25, GPIO_OUT);
  sio_hw->gpio_set |= 1LL<<25;
  while(true){
    // multicore_fifo_push_blocking();
  }
}
