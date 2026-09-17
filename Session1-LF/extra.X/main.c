// NEED TO FIX COMMENTS AND SUCH AND CHANGE TXT TO NEW ALL CODE IS GOOD I THINK




// This time you'll have to do all the setup and coding yourself.
// You are going connect the "Curiosity Nano Explorer" extension card to the
// AVR128DB48 Curiosity Nano, and make the LEDs and buttons work on the explorer.
//
// The extension card is the big, red board with buttons, LEDs and much more.

// Connect the AVR128DB48 Curiosity Nano to the Curiosity Nano Explorer by placing the cNano on the designated space
// in the middle/upper part of the board.
//
// Checkout the datasheet for the Curiosity Nano Explorer to see which pins the
// different LEDs/buttons are connected to. Check the datasheet for the
// AVR128DB48 Curiosity Nano to see which ports and pins on the microcontroller
// that corresponds to those pins from EXT1. Remember: The ports on the
// AVR128DB48 can be different for the LEDs/buttons located on the same
// Explorer.

// F_CPU
// Define F_CPU here
#define F_CPU 24000000UL


// System headers
// Include system headers here
#include <util/delay.h>
#include <avr/io.h>

// LEDs - OLED1 Xplained Pro
// Define LED pins here
#define LED1 1
#define LED2 0
#define LED3 1

// Buttons - OLED1 Xplained Pro
// Define button pins here

#define SW1 4
#define SW2 4
#define SW3 3

int main(void) {

    // Do the following:
    // 1. Set the LEDs as output
    // 2. Set buttons as input
    // 3. Enable pull-ups on the buttons
    //
    // This is exactly the same as in the previous tasks, but with more buttons
    // and LEDs and the pins being different since we're using the extension
    // board
    
    PORTB.DIR |= (1<<LED1);
    PORTC.DIR |= (1<<LED2);
    PORTC.DIR |= (1<<LED3);
    
    PORTD.DIR &= ~(1 << SW1);
    PORTC.DIR &= ~(1 << SW2);
    PORTC.DIR &= ~(1 << SW3);
    
    PORTD.PIN4CTRL |= PORT_PULLUPEN_bm;
    PORTC.PIN4CTRL |= PORT_PULLUPEN_bm;
    PORTC.PIN3CTRL |= PORT_PULLUPEN_bm;
    
    int button_state_1 = 0;
    int button_state_2 = 0;
    int button_state_3 = 0;

    // Turn LEDs off (remember, active-low)
    PORTB.OUT |= (1 << LED1);
    PORTC.OUT |= (1 << LED2);
    PORTC.OUT |= (1 << LED3);

    while (1) {
        // Check if the different buttons are pressed, and turn on the
        // corresponding LED if it is pressed
        
        if (!(PORTD.IN & (1 << SW1))) {
            if (!button_state_1) {

                PORTB.OUT ^= (1 << LED1);
                button_state_1 = 1;
            }
        } else {
            button_state_1 = 0;
        }

        if (!(PORTC.IN & (1 << SW2))) {
            if (!button_state_2) {

                PORTC.OUT ^= (1 << LED2);
                button_state_2 = 1;
            }
        } else {
            button_state_2 = 0;
        }

        if (!(PORTC.IN & (1 << SW3))) {
            if (!button_state_3) {

                PORTC.OUT ^= (1 << LED3);
                button_state_3 = 1;
            }
        } else {
            button_state_3 = 0;
        }

        _delay_ms(1);
    }
}

