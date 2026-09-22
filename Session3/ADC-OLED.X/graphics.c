#include <stdarg.h>
#include <stdio.h>
#include "oled.h"
#include "graphics.h"

// New custom printf function, supports multiple sizes
void graphics_printf(uint8_t size, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    switch (size) {
        case 4: vfprintf(FONT4, fmt, args); break;
        case 5: vfprintf(FONT5, fmt, args); break;
        case 8: vfprintf(FONT8, fmt, args); break;
    }
    va_end(args);
}

/* Clear the screen */
void graphics_clear_screen(){
	// oled_pos(0,0);
	oled_clear_screen();
	display();
}

#define BAR_LEFT   12
#define BAR_RIGHT  115
#define BAR_FIRST  (BAR_LEFT + 1)             // first column inside the bar
#define BAR_WIDTH  (BAR_RIGHT - BAR_LEFT - 1) // 102 columns inside the bar

// Same page/column layout as the old version: the bar sits in pages 1 and 2
static void bar_column(uint8_t col, uint8_t page1, uint8_t page2) {
    buffer[1 * OLED_WIDTH + col] = page1;
    buffer[2 * OLED_WIDTH + col] = page2;
}

// Draw the outline of the loading bar //
void graphics_loading_bar_init(void) {
    bar_column(BAR_LEFT,  0xF8, 0x1F);
    bar_column(BAR_RIGHT, 0xF8, 0x1F);
    for (uint8_t i = 0; i < BAR_WIDTH; i++) {
        bar_column(BAR_FIRST + i, 0x08, 0x10);  // empty: just top and bottom lines
    }
    display();
}

// Set length of loading bar. Between 0 and 1023 //
void graphics_loading_bar_set(uint16_t data) {
    if (data > 1023) data = 1023;
    uint8_t filled = (uint32_t)data * BAR_WIDTH / 1023;
    for (uint8_t i = 0; i < BAR_WIDTH; i++) {
        if (i < filled) bar_column(BAR_FIRST + i, 0xF8, 0x1F);  // filled
        else            bar_column(BAR_FIRST + i, 0x08, 0x10);  // empty
    }
    display();
}

// New print bitmap function using buffer
void graphics_print_bitmap(const uint8_t *bm) {
    for (uint8_t page = 0; page < 4; page++) {
        for (uint8_t xb = 0; xb < 16; xb++) {
            uint8_t d[8];
            for (uint8_t r = 0; r < 8; r++)
                d[r] = pgm_read_byte(&bm[(8 * page + r) * 16 + xb]);
            for (uint8_t b = 0; b < 8; b++) {
                uint8_t db = 0;
                for (uint8_t r = 0; r < 8; r++)
                    db |= ((d[r] >> b) & 1) << r;
                buffer[page * OLED_WIDTH + xb * 8 + b] = db;
            }
        }
    }
    display();
}
