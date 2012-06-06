#define ARM_BASE  0x20000000
#define GPIO_BASE (ARM_BASE + 0x200000)
volatile unsigned *gpio;

#define GPIO_IN(g) *(gpio + ((g)/10)) &= ~(7<<(((g)%10)*3))
#define GPIO_OUT(g) *(gpio + ((g)/10)) |=  (1<<(((g)%10)*3))
#define GPIO_SET(g) *(gpio + 7) = (1<<g)
#define GPIO_CLR(g) *(gpio + 10) = (1<<g)

#include "drivers/gpio.h"

extern "C" void kmain() {
  gpio_select_t *gpio_s = gpio_select_t::get_gpio_select();
  gpio_value_t *gpio_v = gpio_value_t::get_gpio_value();

  for (int i = 7; i < 25; i++) {
    gpio_s->set_function( i, gpio_select_t::function_t::input );
    gpio_s->set_function( i, gpio_select_t::function_t::output );
  }

  gpio_s->set_function( 16, gpio_select_t::function_t::output );
  gpio_v->clr( 16 );

  while (1);
}
