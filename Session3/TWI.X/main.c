#define F_CPU 4000000UL

// Standard C functioins
#include <stdio.h>

// AVR LibC functions
#include <avr/io.h>
#include <util/delay.h>

// Custom libraries
#include "twi.h"
#include "uart.h"
#include "vcnl4200.h"


// Character buffer to store the UART string.
char uart_str[256];

// In this exercise you will write a driver for the TWI module. You will use
// your TWI driver to read and write data to configure the sensor and to read
// from the sensor. A functional driver for the sensor is provided (vcnl4200.h).
// The sensor data that you have read can then be sent over UART (uart.h).
// These build on the TWI driver. No help beyond the function headers is
// provided.
// 
// To start, it's recommend you:
// a) Glance over the chapter on TWI in the AVR128DB48 datasheet
// b) Find out the address of the proximity sensor
int main() {
    // Initialize TWI

    // Initialize USART

    // Initialize proximity sensor

    while (1) {
        // Read proximity sensor value

        // Format the data as a string using snpritf.
        // This command can be quite tricky to use, I recommend
        // looking at this site to understand it:
        // https://www.geeksforgeeks.org/snprintf-c-library/
        // For all the formatting options look at:
        // https://cplusplus.com/reference/cstdio/printf/
        // 
        // A quick description is that it takes a pointer to
        // an array of character, followed by the size of that
        // character array. The next argument is a format string
        // that specifies how the data should be formatted.
        // The last argument is a pointer to the data that
        // should be formatted.

        // Print the formatted string over uart
        
        // Wait a bit
        _delay_ms(1000);

        // Feel free to play around with the settings in the proximity
        // sensor. Try changing the gain, the integration time,
        // and the proximity threshold.
    }
}

