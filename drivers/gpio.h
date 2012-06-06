#ifndef __DRIVERS_GPIO__
#define __DRIVERS_GPIO__

#include <stdint-gcc.h>

typedef uint8_t pin_t;

class gpio_select_t {
  public:
    enum class function_t : uint8_t {
      input = 0,
      output = 1,
      alternate_0 = 2,
      alternate_1 = 3,
      alternate_2 = 4,
      alternate_3 = 5,
      alternate_4 = 6,
      alternate_5 = 7,
    };
    
    void set_function( pin_t pin, function_t function );
    
    static gpio_select_t *get_gpio_select();
  
  private:
    volatile uint32_t regs[6];
};
static_assert( sizeof( gpio_select_t ) == 6*4, "GPIO Select register has an unexpected size." );

class gpio_value_t {
  public:
    void set( pin_t pin );
    void clr( pin_t pin );
  
    static gpio_value_t *get_gpio_value();
    
  private:
    volatile uint32_t regs_set[2];
    uint32_t dummy;
    volatile uint32_t regs_clr[2];
};
static_assert( sizeof( gpio_value_t ) == 5*4, "GPIO Value register has an unexpected size." );

#endif /* __DRIVERS_GPIO__ */