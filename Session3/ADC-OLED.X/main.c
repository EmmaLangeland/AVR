#include <stdint.h>
#define F_CPU 4000000UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>

#include "adc.h"
#include "oled.h"
#include "twi.h"
#include "graphics.h"

// Define these
#define KLAKK_CHANNEL ADC_MUXPOS_AIN6_gc // Want to use input from ADC6 (on explorer)
#define SW0_bm        
#define SW0_PORT      

int main(void) {
    // Initialize I2C (TWI) and wait a bit (~2 seconds)
    // Is there a prepared function in another c-file?
    

    // Initialize the OLED
    // Is there a prepared function in another c-file?
    

    // Type a char
    // fprintf can print to the OLED
    // First argument is the font given in fonts.h (ex. FONT4)
    // Second argument is the string you want to print
    

    // Now you want to find a function that can flush the display buffer contents to the display
    // Check oled.h
    

    // Empty loop to keep the program running
    while(1) {;}

    ////  SECOND TASK - Finish and test the code over this part before continuing   //// 

    //// This task is about reading from the potmeter and displaying it on the OLED.
   
    // Set button as input and pullup
    


    // We want to initialize the ADC, and wait a bit (~2 seconds)
    // Is there a prepared function in another c-file?
    

    // Lets start with clearing the screen from task 1.
    // Is there a prepared function in another c-file?
    
    

    // Now we need to print a bitmap, lets us the OV logo.
    // Are there any files related to graphics, that may have a premade function?
    // (We have made a bitmap for the OV logo, "OV")
    

    // Wait a bit (~2 seconds)
    

    // We now want to desplay the bar that will show the value of the potmeter.
    // We therefore need to defind it. Lets use a loading bar for this.
    // Because we already have a bitmap on the screen, we need to clear it first.
    // Then we can initialize the loading bar. is there a function for this somewhere?
    

    // Lets start the main loop, where we will read the potmeter and display it on the OLED.
    // Remember to comment out or remove the previous while loop above
    /*
    while (1) { 

        // We want to read data from the ADC, check adc.c
        // We want to keep it to 512 steps, so we need to shift the result down by 2 bits (divide by 4)
        

        // We have to define where on the OLED we want to print the value of the potmeter.
        // Is there any functions that can be used to set the position of the cursor on the OLED? (Check oled.h)
        // Set pos to coordinates (0, 12).
        

        // Lets print some text to the OLED. 
        // We want to print the value of the potmeter, so we need to use a function that can print formatted text. Check graphics.c
        // Size suggestions: 1. size: 5, 2. size: 8
        // Lets print "OV-POT read: " first, then the value of the potmeter. (It needs two lines)
        // To print the data, we need to use the format specifier "%4u" to print an unsigned integer with a width of 4 characters, 
        // and then the data from the potmeter.
        

        // We want to set the value of the potmeter to the loading bar. Check graphics.c
        

        // We want the voltage_integer and voltage_fraction to be displayed on the OLED.
        // The voltage is calculated by: data * 323ul / 100000ul
        // The fraction is calculated by: (data * 323ul % 100000ul) / 1000
        

        // We want to set the position of the cursor on the OLED to the next line, and print the voltage.
        // Set pos to (3, 12)
        

        // We want to print the voltage to the OLED.
        // Try printing this "Voltage: voltage_integer.voltage_fraction V". With the values inserted.
        // (It needs two lines)
        

        // Remember to display it.
          

        // Lets also add a button to the program. When pressed, the button will display the OV logo again.
        // Let the logo be displayed until the button is released. Remeber to clear the screen
        
    }
    */
}