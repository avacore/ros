#include "gpio.h"

#define ARM_BASE  0x20000000
#define GPIO_BASE (ARM_BASE + 0x200000)

gpio_select_t *gpio_select_t::get_gpio_select() {
  return reinterpret_cast< gpio_select_t * >( GPIO_BASE );
}

void gpio_select_t::set_function( uint8_t pin, function_t function ) { 
  uint8_t idx = pin / 10;
  uint8_t off = ( pin % 10 ) * 3;
  
  uint32_t mask = ~( 0x7 << off );
  uint32_t value = ( int( function ) << off );
  
  this->regs[idx] = ( this->regs[idx] & mask ) | value;
}

gpio_value_t *gpio_value_t::get_gpio_value() {
  return reinterpret_cast< gpio_value_t * >( GPIO_BASE + 0x1C );
}

void gpio_value_t::clr( uint8_t pin ) { 
  uint8_t idx = pin / 32;
  uint8_t off = pin % 32;
  
  uint32_t value = ( 1 << off );
  
  this->regs_clr[idx] = value;
}

