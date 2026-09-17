#define F_CPU 4000000UL


#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

// Define the LED pins
#define LED_R 0 
#define LED_G 1 
#define LED_B 2 

// Define the LED ports
#define LED_R_PORT PORTD
#define LED_G_PORT PORTD
#define LED_B_PORT PORTD

// In this exercise, you will use PWM to control the Red, Green, and Blue
// Brightness on the RGB led on the Curiosity Nano Explorer.
// Once we have PWM set up, controling the brightness is super easy!
//
// NB: These LEDs are on the Curiosity Nano Explorer board!
int main() {
    // 1. Set up the LEDs as outputs.
    // Feel free to copy this from previous excercies

    // 2. Set up pin multiplexing
    // In dataheet:
    // Section 17, PORTMUX we see that if we want to use TCA0 with PD0, PD1,
    // and PD2 we need to use portmux to change TCA0 to Port D. Look at
    // PORTMUX.TCAROUTEA register for this and set it to the appropriate value.

    // 3. Enable split mode
    // We will be using timer TCA0 in Split (not Single) mode. We use Split mode
    // to output waveforms on WO0, WO1, and WO2.
    // It is highly recommended that you read chapter 23.3.3.4 and 20.3.3.6 in
    // the AVR128DB48 datasheet. There you will find a sub-chapter on the
    // single-slope PWM we will be using.
    //
    // First, set the split mode. Look in section 20.7.4 in the data sheet.

    // 4. Enable the timer
    // Then, enable the TCA and set the prescaler. See section 20.7.1.
    // Set the prescaler to, for example, 1.

    // 5. Enable the compare channels
    // Enable low compare 0, 1, and 2 to get output on WO0, WO1, and WO2.
    // See section 20.7.2.

    // 6. Set the compare values
    // Set period for low compare. See section 20.7.12.
    // Set it to, for example, 0xFF

    // 7. Set the PWM duty cycle

    while(1) {
        // 8. Have fun with the brightness!
        // To now adjust the brightness of the LEDs, we can modify
        // TCA.SPLIT.LCMPx. Try for example incrementing the LCMPx values in a
        // loop with a delay
    }

    return 0;
}

