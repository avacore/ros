#include "drivers/gpio.h"
#include "drivers/uart.h"

extern "C" void kmain() {
  gpio_select_t *gpio_s = gpio_select_t::get_gpio_select();
  gpio_value_t *gpio_v = gpio_value_t::get_gpio_value();

  for (int i = 7; i < 25; i++) {
    gpio_s->set_function( i, gpio_select_t::function_t::input );
    gpio_s->set_function( i, gpio_select_t::function_t::output );
  }

  gpio_s->set_function( 16, gpio_select_t::function_t::output );
  gpio_v->clr( 16 );
  
  uart_t *uart = uart_t::get_uart();
  uart->setup( uart_t::baudrate_t::b115200 );

  gpio_v->set( 16 );

  for( int i = 0; i < 1024; ++i ) {
    uart->put( '!' );
  }
  
  gpio_v->clr( 16 );

  while( 1 ) {}
}
