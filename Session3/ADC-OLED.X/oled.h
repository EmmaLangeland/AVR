/*
 * SSD1306 OLED Driver
 * 
 * Author: Sebastian Gabrielli
 * Date: 2025-03-31
 * 
 * This driver is a combination of the previous SSD1306 driver that existed in this file,
 * the official SSD1306 datasheet, and the Adafruit SSD1306 driver available at:
 * https://github.com/adafruit/Adafruit_SSD1306/tree/master
 * 
 * This implementation aims to provide a simple and easy-to-use interface for controlling
 * the SSD1306 OLED display, making it suitable for beginners as part of the "AVR Kurs"
 * introductory course.
 * 
 * License: MIT License
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef DRIV_OLED_H_
#define DRIV_OLED_H_

#define F_CPU 4000000UL

// AVR specific headers
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// C standard headers
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h> // memset

// Program headers
#include "fonts.h"
#include "graphics.h"
#include "twi.h"

// OLED I2C address
#define OLED_ADDR 0x3D

// Some custom defines
#define SSD1306_PREAMBLE_COMMAND    0x00
#define SSD1306_PREAMBLE_DATA       0x40

// Chargepump values
#define SSD1306_CHARGEPUMP_ENABLE   0x14
#define SSD1306_CHARGEPUMP_DISABLE  0x00

// Memory mode values
#define SSD1306_MEMORYMODE_HORIZONTAL   0x00  // A[1:0] = 00b, Horizontal Addressing Mode
#define SSD1306_MEMORYMODE_VERTICAL     0x01  // A[1:0] = 01b, Vertical Addressing Mode
#define SSD1306_MEMORYMODE_PAGE         0x02  // A[1:0] = 10b, Page Addressing Mode (RESET)
#define SSD1306_MEMORYMODE_INVALID      0x03  // A[1:0] = 11b, Invalid

// COM Pins Configuration
#define SSD1306_COM_PINS_SEQUENTIAL           0x00  // A[4] = 0b, Sequential COM pin configuration
#define SSD1306_COM_PINS_ALTERNATIVE          0x10  // A[4] = 1b (RESET), Alternative COM pin configuration
#define SSD1306_COM_LEFT_RIGHT_DISABLE        0x00  // A[5] = 0b (RESET), Disable COM Left/Right remap
#define SSD1306_COM_LEFT_RIGHT_ENABLE         0x20  // A[5] = 1b, Enable COM Left/Right remap

#define OLED_WIDTH                  128
#define OLED_HEIGHT                 64

/*--------------------------------------------------*\
|                                                    |
|          SSD1306 Display Driver Defines            |
|                                                    |
|          Taken from Adafruit_SSD1306.h             |
|          https://github.com/adafruit/              |
|          Adafruit_SSD1306/blob/master/             |
|          Adafruit_SSD1306.h                        |
|                                                    |
\*--------------------------------------------------*/
#define SSD1306_MEMORYMODE 0x20          ///< See datasheet
#define SSD1306_COLUMNADDR 0x21          ///< See datasheet
#define SSD1306_PAGEADDR 0x22            ///< See datasheet
#define SSD1306_SETCONTRAST 0x81         ///< See datasheet
#define SSD1306_CHARGEPUMP 0x8D          ///< See datasheet
#define SSD1306_SEGREMAP 0xA0            ///< See datasheet
#define SSD1306_DISPLAYALLON_RESUME 0xA4 ///< See datasheet
#define SSD1306_DISPLAYALLON 0xA5        ///< Not currently used
#define SSD1306_NORMALDISPLAY 0xA6       ///< See datasheet
#define SSD1306_INVERTDISPLAY 0xA7       ///< See datasheet
#define SSD1306_SETMULTIPLEX 0xA8        ///< See datasheet
#define SSD1306_DISPLAYOFF 0xAE          ///< See datasheet
#define SSD1306_DISPLAYON 0xAF           ///< See datasheet
#define SSD1306_COMSCANINC 0xC0          ///< Not currently used
#define SSD1306_COMSCANDEC 0xC8          ///< See datasheet
#define SSD1306_SETDISPLAYOFFSET 0xD3    ///< See datasheet
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5  ///< See datasheet
#define SSD1306_SETPRECHARGE 0xD9        ///< See datasheet
#define SSD1306_SETCOMPINS 0xDA          ///< See datasheet
#define SSD1306_SETVCOMDETECT 0xDB       ///< See datasheet

#define SSD1306_SETLOWCOLUMN 0x00  ///< Not currently used
#define SSD1306_SETHIGHCOLUMN 0x10 ///< Not currently used
#define SSD1306_SETSTARTLINE 0x40  ///< See datasheet

#define SSD1306_EXTERNALVCC 0x01  ///< External display voltage source
#define SSD1306_SWITCHCAPVCC 0x02 ///< Gen. display voltage from 3.3V

#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26              ///< Init rt scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27               ///< Init left scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 ///< Init diag scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A  ///< Init diag scroll
#define SSD1306_DEACTIVATE_SCROLL 0x2E                    ///< Stop scroll
#define SSD1306_ACTIVATE_SCROLL 0x2F                      ///< Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3             ///< Set scroll range

/*-------------------------*\
|                           |
|    Function prototypes    |
|                           |
\*-------------------------*/

void clear_buffer(bool white);

/* Flush the display buffer contents to the display */
void display();

/* Initiate and configure OLED */
void oled_init();

/* Hardware reset the screen */
void oled_reset();

/* Write multiple commands, or a command with parameters */
void oled_write_commands(uint8_t *commands, uint16_t num_commands);

/* Write a single command */
void oled_write_single_command(uint8_t command);

/* Write data */
void oled_write_data(uint8_t *commands, uint16_t len);

// /* Clear the screen */
void oled_clear_screen();

// /* Clear one line */
void oled_clear_line(uint8_t line);

// /* Go to given row*/
void oled_goto_line(uint8_t line);

// /* Go to given row and column*/
void oled_pos(uint8_t row, uint8_t col);

// /* Return current row*/
uint8_t oled_get_current_line();

// /* Set brightness, 0-255 */
void oled_set_brightness(uint8_t lvl);


/************************************
  Writing text to OLED
  Use ASCII code, Font types: FONT8 (8x8), FONT5 (5x7), FONT4 (4x6)
  Each font has an individual file stream for convenience use with "fprintf()"
  e.g. fprintf(FONT5,"Hello world \n")
 *************************************/

/* Write a character to the screen with font 4 to current position*/
int oled_putchar4(char character, FILE * stream);

/* Write a character to the screen with font 5 to current position*/
int oled_putchar5(char character, FILE* stream);

/* Write a character to the screen with font 8 to current position*/
int oled_putchar8(char character, FILE* stream);

static FILE oled_stream_font4 = FDEV_SETUP_STREAM(oled_putchar4, NULL, _FDEV_SETUP_WRITE);
static FILE oled_stream_font5 = FDEV_SETUP_STREAM(oled_putchar5, NULL, _FDEV_SETUP_WRITE);
static FILE oled_stream_font8 = FDEV_SETUP_STREAM(oled_putchar8, NULL, _FDEV_SETUP_WRITE);

#define FONT4 (&oled_stream_font4)
#define FONT5 (&oled_stream_font5)
#define FONT8 (&oled_stream_font8)

// Noe buffer greier?
extern uint8_t buffer[];

#endif /* DRIV_OLED_H_ */
