<<<<<<< HEAD
/* 
 * File:   main.c
 * Author: sebgab
 *
 * Created on February 23, 2025, 1:16 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
=======
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

    /* LF start */
    // Configure the pins as outputs
    LED_R_PORT.DIRSET = (1 << LED_R);
    LED_G_PORT.DIRSET = (1 << LED_G);
    LED_B_PORT.DIRSET = (1 << LED_B);

    /* LF end */

    // 2. Set up pin multiplexing
    // In dataheet:
    // Section 17, PORTMUX we see that if we want to use TCA0 with PD0, PD1,
    // and PD2 we need to use portmux to change TCA0 to Port D. Look at
    // PORTMUX.TCAROUTEA register for this and set it to the appropriate value.

    /* LF start */
    PORTMUX.TCAROUTEA = PORTMUX_TCA0_PORTD_gc;
    /* LF end */

    // We will be using timer TCA0 in Split (not Single) mode. We use Split mode
    // to output waveforms on WO4 and WO5, see Figure 4-1 in the Curiosity Nano
    // Hardware User Guide. It is highly recommended that you read
    // chapter 20.3.3.4 and 20.3.3.6 in the megaAVR® 0-series. There you will
    // find a sub-chapter on the single-slope PWM we will be using.
    //
    // First, set the split mode. Look in section 20.7.4 in the data sheet.

    /* LF start */

    // Enable split mode
    //TCA0.SINGLE.CTRLD |= (1 << TCA_SPLIT_SPLITM_bp);
    TCA0.SPLIT.CTRLD |= (1 << TCA_SPLIT_SPLITM_bp);

    /* LF end */

    // Then, enable the TCA and set the prescaler. See section 20.7.1. Set the
    // prescaler to for example 1.
    /* LF start */

    // Enable TCA end set prescaler to 1
    TCA0.SPLIT.CTRLA |=
            (1 << TCA_SPLIT_ENABLE_bp)
        |   (TCA_SPLIT_CLKSEL_DIV1_gc)
        ;

    /* LF end */

    // Enable high compare 0, 1, and 2 to get output on WO0, WO1, and WO2.
    // See section 20.7.2.

    /* LF Start */

    // Enable high compare on 0, 1, and 2 to get output on WO0, WO1, and WO2
    // See figure /shrug
    TCA0.SPLIT.CTRLB |=
            (1 << TCA_SPLIT_LCMP0EN_bp) // Channel0 enable
        |   (1 << TCA_SPLIT_LCMP1EN_bp) // Channel1 enable
        |   (1 << TCA_SPLIT_LCMP2EN_bp) // Channel2 enable
        ;

    /* LF end */


    // Set period for high compare. See section 20.7.13. Set it to for example
    // 0xFF

    /* LF Start */

    // Set the period for high compare.
    // See figure xx in the datasheet.
    // Effectively, this sets the PWM period.
    TCA0.SPLIT.LPER = 0xFF;

    // Sett the PWM duty cycle
    TCA0.SPLIT.LCMP0 = 0x00;
    TCA0.SPLIT.LCMP1 = 0x7C;
    TCA0.SPLIT.LCMP2 = 0xFF;

    /* LF end */

    while(1) {
        // To now adjust the brightness of the LEDs, we can modify
        // TCA.SPLIT.HCMPx. Try for example incrementing the HCMPx values in a
        // loop with a delay

        /* LF Start */
        for (uint8_t i = 0; i < 0xFF; i++) {
            TCA0.SPLIT.LCMP1 = i;
            TCA0.SPLIT.LCMP2 = 0xFF - i;
            _delay_ms(5);
        }

        for (uint8_t i = 0xFF; i > 0; i--) {
            TCA0.SPLIT.LCMP1 = i;
            TCA0.SPLIT.LCMP2 = 0xFF - i;
            _delay_ms(5);
        }
        /* LF end */

    }

    return 0;
>>>>>>> 54a3b8b612a2ac15d360c2ee5e4eafed6be53f8f
}

