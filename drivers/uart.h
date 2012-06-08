#ifndef __DRIVERS_UART__
#define __DRIVERS_UART__

#include <stdint-gcc.h>

const uint32_t uart_clk = 2978972;

class uart_t {
  public:
    enum class baudrate_t : uint32_t {
      b115200 = uart_clk*4/115200,
    };

    void setup( baudrate_t baudrate );

    void put( char b );
    
    static uart_t *get_uart();
    
  private:
    volatile uint32_t regs[32];
};

#endif /* __DRIVERS_UART__ */
