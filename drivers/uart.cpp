#include "uart.h"

#include "gpio.h"

void uart_t::put( char b ) {
  while( regs[6] & 0x0028 ) {}
  
  regs[0] = b;
}

void uart_t::setup( baudrate_t baudrate ) {
  uint32_t divisor = uint32_t( baudrate );
  gpio_select_t *gpio_s = gpio_select_t::get_gpio_select();
  
  regs[12] = 0x0000;
  regs[9] = divisor >> 6;
  regs[10] = divisor & 0x3f;
  regs[11] = 0x0070;
  regs[12] = 0x0100;
  regs[13] = 0x0012;
  regs[14] = 0x0000;
  regs[17] = 0x07ff;
  regs[12] = 0x0101;

  gpio_s->set_function( 14, gpio_select_t::function_t::alternate_0 );
  gpio_s->set_function( 15, gpio_select_t::function_t::alternate_0 );
}

uart_t *uart_t::get_uart() {
  return reinterpret_cast< uart_t * >( 0x20201000 );
}

