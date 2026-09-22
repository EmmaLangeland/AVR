#include "oled.h"

static uint8_t oled_current_line_num;

#define OLED_RESET_bm   PIN5_bm
#define OLED_RESET_PORT PORTB

//------------------------------------------------------------

// Create a buffer to hold the current display data
#define BUF_SIZE (128 * ((64 + 7) / 8))
uint8_t buffer[BUF_SIZE] = {0};

// Create some variables to keep track of where we are in the display buffer
uint8_t x = 0;
uint8_t y = 0;

// uint8_t oled_get_current_line() { return oled_current_line_num; }

void clear_buffer(bool white) {
    memset(buffer, white ? 0xFF : 0x0, BUF_SIZE);
}

void display() {
    // Set the page start address
    uint8_t page_command[] = {0x22, 0x00, 0xFF};
    oled_write_commands(page_command, sizeof(page_command));

    // Set the column address
    uint8_t col_command[] = {0x21, 0x00, OLED_WIDTH - 1};
    oled_write_commands(col_command, sizeof(col_command));

    // Transmit the buffer
    oled_write_data(buffer, BUF_SIZE);
}

void oled_init() // Documentation on oled screen on:
                 // https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf
{
    // We start off by resetting the display.
    // This ensures the display starts "fresh" and does
    // not have any weird config applied previously.
    OLED_RESET_PORT.DIRSET = OLED_RESET_bm;
    oled_reset();

    // Now that the display is reset we can start to configure it
    // To do this we follow the configuration flor that is shown in
    // chaper three of the display controller datasheet (p. 64)
    // With some adjustments of course...
    // The configuration flow for initialization is mostly based on
    // Adafruit's driver

    // Start by turning the display off
    // Datasheet: 10.1.12 (p. 37)
    oled_write_single_command(SSD1306_DISPLAYOFF);

    // Set the clock divisor to the recommended value
    // Datasheet: 10.1.16 (p. 40)
    uint8_t clockdiv_commands[2] = {SSD1306_SETDISPLAYCLOCKDIV, 0x80};
    oled_write_commands(clockdiv_commands, 2);

    // Set the mupliplexer ratio
    // Datasheet: 10.1.11 (p. 37)
    uint8_t multiplexer_commands[2] = {SSD1306_SETMULTIPLEX, OLED_WIDTH - 1};
    oled_write_commands(multiplexer_commands, 2);

    // Set the display offset
    // Datasheet: 10.1.15 (p. 37 / p. 31)
    uint8_t offset_commands[2] = {SSD1306_SETDISPLAYOFFSET, 0x00}; // No offset
    oled_write_commands(offset_commands, 2);

    // Set the display startline
    // Here we want the startline to be 0 so we or that into it
    // Datasheet: 10.1.6 (p. 36/ p.32)
    oled_write_single_command(SSD1306_SETSTARTLINE | 0x00);

    // Enable the chargepump
    // Datasheet: (p. 62)
    uint8_t chargepump_commands[2] = {SSD1306_CHARGEPUMP, SSD1306_CHARGEPUMP_ENABLE};
    oled_write_commands(chargepump_commands, 2);

    // Set the memory addressing mode of the display.
    // We set it to be horizontal. This means that we first fill a row
    // of pixel data on the display, then we move one row down and
    // start filling the next row of pixel data.
    // Datasheet: 10.1.3 (p. 37 / p.30)
    uint8_t memory_addressing_command[2] = {SSD1306_MEMORYMODE, SSD1306_MEMORYMODE_HORIZONTAL};
    oled_write_commands(memory_addressing_command, 2);

    // Set the segment remap
    // We want to set it to remap
    // Datasheet: 10.1.8 (p. 36 / p. 31)
    oled_write_single_command(SSD1306_SEGREMAP | 0x01);

    // Set the COM output scan direction
    // We need to do this as we have remapped the display
    // Datasheet: 10.1.14 (p. 37 / p.31)
    oled_write_single_command(SSD1306_COMSCANDEC);

    // Setup the device COM pins
    // Datasheet: 10.1.18 (p. 40 / p.31)
    uint8_t com_pins_commands[2] = {SSD1306_SETCOMPINS, 0x12};
    oled_write_commands(com_pins_commands, 2);

    // Set the display contrast
    // Datasheet: 10.1.7 (p. 36 / p. 28)
    uint8_t contrast_commands[2] = {SSD1306_SETCONTRAST, 0xCF};
    oled_write_commands(contrast_commands, 2);

    // Set precharge period
    // Datasheet: 10.1.17 (p. 40 / p. 32)
    uint8_t precharge_commands[2] = {SSD1306_SETPRECHARGE, 0xF1};
    oled_write_commands(precharge_commands, 2);

    // Set VCOM regulator output
    // Datasheet: 10.1.19 (p. 43 / p. 32)
    uint8_t vcom_commands[2] = {SSD1306_SETVCOMDETECT, 0x40};
    oled_write_commands(vcom_commands, 2);

    // Set the display to show the entire contents when enabled
    // Datasheet: 10.1.9 (p. 37 / p. 28)
    oled_write_single_command(SSD1306_DISPLAYALLON_RESUME);

    // Set the display to normal mode
    // Datasheet: 10.1.10 (p. 37 / p. 28)
    oled_write_single_command(SSD1306_NORMALDISPLAY);

    // Disbale scrolling the display contents
    // Datasheet: 10.2.3 (p. 46 / p. 29)
    oled_write_single_command(SSD1306_DEACTIVATE_SCROLL);

    // Turn the display on
    // Datasheet: 10.1.12 (p. 37 / p. 28)
    oled_write_single_command(SSD1306_DISPLAYON);

    // Clear the display
    oled_clear_screen();
    display();
}

/* Hardware reset the screen */
void oled_reset() {
    OLED_RESET_PORT.OUTCLR = OLED_RESET_bm;
    _delay_ms(10);
    OLED_RESET_PORT.OUTSET = OLED_RESET_bm;
    _delay_ms(10);
}

/* Write command */
void oled_write_commands(uint8_t *commands, uint16_t num_commands) {
    // Start a TWI transfer
    TWI_load_addr(OLED_ADDR, true);

    // Send the preample to tell the display it is going to receive commands
    uint8_t preamble = SSD1306_PREAMBLE_COMMAND;
    TWI_write_data(&preamble, 1);

    // Transmit the commands
    TWI_write_data(commands, num_commands);

    // Stop the SPI transfer
    TWI_stop();
}

void oled_write_single_command(uint8_t command) {
    oled_write_commands(&command, 1);
}

/* Write data*/
void oled_write_data(uint8_t *data, uint16_t len) {
    // Start a TWI transfer
    TWI_load_addr(OLED_ADDR, true);

    // Send the preample to tell the display it is going to receive commands
    uint8_t preamble = SSD1306_PREAMBLE_DATA;
    TWI_write_data(&preamble, 1);

    // Transmit the commands
    TWI_write_data(data, len);

    // Stop the SPI transfer
    TWI_stop();
}

/* Clear the display buffer */
void oled_clear_screen() {
    // Clear the buffer
    memset(buffer, 0x00, BUF_SIZE);

    // Reset the position
    x = 0;
    y = 0;
}

// Go to given row //
void oled_goto_line(uint8_t line) {
    oled_write_single_command(0xb0 + line);
    oled_current_line_num = line;
}

// New Oled Pos, sets the cursor instead //
void oled_pos(uint8_t row, uint8_t col) {
    y = row;   // page (0-3 on a 128x32 panel)
    x = col;   // pixel column
}

// Replacement for the putchar functions
static int put_glyph(char c, const unsigned char *font, uint8_t width, uint8_t spacing) {
    if (c == '\n') { y++; x = 0; return 0; }
    if (c < 32 || c > 126) return 0;
    if (x + width + spacing > OLED_WIDTH) { x = 0; y++; }
    if (y >= OLED_HEIGHT / 8) return 0;
    const unsigned char *glyph = font + (uint16_t)(c - 32) * width;
    for (uint8_t i = 0; i < width; i++)
        buffer[y * OLED_WIDTH + x++] = pgm_read_byte(&glyph[i]);
    for (uint8_t i = 0; i < spacing; i++)
        buffer[y * OLED_WIDTH + x++] = 0;
    return 0;
}

int oled_putchar4(char c, FILE *s) { (void)s; return put_glyph(c, &ffont4[0][0], 4, 0); }
int oled_putchar5(char c, FILE *s) { (void)s; return put_glyph(c, &ffont5[0][0], 5, 1); }
int oled_putchar8(char c, FILE *s) { (void)s; return put_glyph(c, &ffont8[0][0], 8, 0); }

// Set brightness, 0-255 //
void oled_set_brightness(uint8_t lvl) {
    oled_write_single_command(0x81); // Set brightness command
    oled_write_single_command(lvl);  // Set brightness level
}
