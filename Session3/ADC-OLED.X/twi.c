#include "twi.h"
#include <stdint.h>

void TWI_init() {
    // Init pins
    PORTA.DIRSET = PIN2_bm | PIN3_bm;
    PORTA.PINCONFIG = PORT_PULLUPEN_bm;
    PORTA.PINCTRLUPD = PIN2_bm | PIN3_bm;

    // Set the TWI clock frequency
    TWI0.MBAUD = (F_CPU / (2 * TWI_FREQ)) - 5; // Set baud rate for TWI

    // Initialize the address register
    TWI0.MADDR = 0x00;

    // Initialize the data register
    TWI0.MDATA = 0x00;

    // Set the bus state as idle
    TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc;

    // Enable TWI
    TWI0.MCTRLA |= TWI_ENABLE_bm; // Enable TWI
}

void TWI_load_addr(uint8_t device_address, bool write) {
    // Load the address in bit 1-7 and the read/write setting in bit 0
    // The read/write setting is such that a write is 0, and read is 1
    if (write == true) {
        TWI0.MADDR = (device_address << 1) & ~(1 << 0);
    } else {
        TWI0.MADDR = (device_address << 1) |  (1 << 0);
    }

   // Wait for the address to be transmitted
   while (!(TWI0.MSTATUS & TWI_WIF_bm)); // Wait for write interrupt flag
}

void TWI_write_data(uint8_t *data, uint16_t len) {
    // Loop through the data, writing it to the bus one byte at a time
    for (int i = 0; i < len; i++) {
        // Load data into the data register
        TWI0.MDATA = data[i];

        // Wait for the data to be transmitted
        while (!(TWI0.MSTATUS & TWI_WIF_bm)); // Wait for write interrupt flag

        // Wait for the ACK flag
        // while (!(TWI0.MSTATUS & TWI_RXACK_bm)); // Wait for ACK flag
    }
}

void TWI_stop() {
    TWI0.MCTRLB = TWI_MCMD_STOP_gc; // Send stop condition
}

void TWI_write_transaction(uint8_t device_address, uint8_t *data, uint16_t len) {
    // Start the transactionn
    TWI_load_addr(device_address, true);

    // Send the data
    TWI_write_data(data, len);

    // Stop the transaction
    TWI_stop();
}