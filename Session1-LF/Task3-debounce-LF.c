/* 
 * File:   main.c
 * Author: sebgab
 *
 * Created on February 23, 2025, 1:00 PM
 */

 #define F_CPU 3333333UL
 #include <util/delay.h>
 #include <avr/io.h>
 
 // The pins are found in the data sheet
 // Define the LED pin 
 #define LED0 3
 
 // Define the button pin
 #define SW0 2
 
 int button_state = 0;
 
 int main(void) {
     // Set the LED pin as output
     PORTB.DIR |= (1 << LED0);
     
     // Set the button as input
     PORTB.DIR &= ~(1 << SW0);
     
     // Set button pin as pull-up
     PORTB.PIN2CTRL |= PORT_PULLUPEN_bm;
     
     // Runs continuously
     while (1) {
         // Check if button is pressed
         if (!(PORTB.IN & (1 << SW0))){
             if (button_state == 0){
             // Toggle LED if BUTTON press
             PORTB.OUTTGL = (1 << LED0);
             button_state = 1;
             } 
         } else{
             button_state = 0;
         }
         _delay_ms(1);
     }
     return 0;
 }