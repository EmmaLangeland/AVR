//main.c for button.X
#include <stdio.h>
#include <stdlib.h>

#define F_CPU 4000000UL

#include <avr/io.h>
#include <util/delay.h>

// LED0, PB3
#define LED0 3

// Check out the AVR128DB48 Curiosity Nano Hardware User Guide to find
// the correct port and pin for the button
#define SW0 2 // -- Fill in the pin for the button here ---

int main(void) {
    // We want to send signals to the LEDs, in order to turn it off and on.
    // We also want to be able to read the button.
    // This is done by setting bits in the PORTx.DIR register (in this case
    // PORTF.DIR and PORTB.DIR)
    // PORTx.DIR: 1 is output, 0 is input

    // LED: 1 LED is off, 0 LED is on
    // Button: 1 Button is open, 0 button is pressed
    //
    // Bit set logic:
    // Set to 1: REG |= ( 1 << BIT_POS )
    // Set to 0: REG &= ~( 1 << BIT_POS )

    // In order to read from the button, we need to give it a ground
    // reference, via a pull-up resistor. If we don't, the button pin will have
    // a floating ground, and hence its value will be undefined. On the
    // AVR128DB48, we enable pull-up by setting the "PORT_PULLUPEN" bit in
    // "PORTx.PINnCTRL" high. See datasheet section 18 (I/O-ports).

    // It's your time to do some stuff! Do the following:
    // 1 - Find which pin and port the SW0 button is on. Check the AVR128DB48
    // Curiosity Hardware User Guide to find the correct port and pin. Then
    // define the pin for the button at the line "#define SW0".

    // 2 - Set LED0 as output
    PORTB.DIR |= ( 1 << LED0 );

    // 3 - Set SW0 as input
    PORTB.DIR &= ~( 1 << SW0 );

    // 4 - Enable pull-up on button SW0
    PORTB.PIN2CTRL |= PORT_PULLUPEN_bm;

    while (1) {
        // Here, you want to check if a button is pressed, and if yes, turn on
        // LED0. If no, then do the opposite. Similar to setting pins with
        // PORTx.OUT, we can read pins with PORTx.IN In order to check a pin
        // value, mask out that particular bit (use bitwise AND). Bit masking is
        // done like this: (REGISTER & (1 << BIT_POS)), which selects bit
        // BIT_POS from register. If that bit is 0, the result will be 0. If it
        // is 1, the result will be greater than 0 (depending on bit position).     

        // Do the following:
        // 1 - check if button SW0 is pressed
        // 2 - if so, turn LED0 on
        // 3 - if not, turn LED0 off

        if  (PORTB.IN & ( 1 << SW0 )){ // (PORTB.IN & ~PIN2_bm)
            PORTB.OUT |= ( 1 << LED0 ); //PORTB.OUT = PIN3_bm
        }
        else {
            PORTB.OUT ^= ( 1 << LED0 );
        }

    }
}


