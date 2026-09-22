#include "twi.h"
#include <avr/io.h>
#include <stdint.h>

void TWI_init() {
    // Initialize the pins as outputs

    // Set the TWI clock frequency
    // The formula to calculate the clock is found
    // in the AVR128DB48 datasheet on page 425.
    // Feel free to use the F_CPU and TWI_FREQ values
    // defined in the header file.

    // Set the bus state as idle
    // It defauts to being in an unknown state
    // when the device is first powered on.
    // This is why we need to set it to idle
    // See the TWI0.MSTATUS register.

    // Enable TWI in the master mode
    // See the TWI0.MCTRLA register.
}

void TWI_load_addr(uint8_t device_address, bool write) {
    // This function loads the device address into the TWI0.MADDR register.
    // NB: Bits 1-7 are the address bits
    //     Bit 0 is the read/write setting
    //
    // NBNB: We need to wait for the write interrupt flag when we are
    //       loading the device address for writing.
}

void TWI_write_data(uint8_t *data, uint16_t len) {
    // This function writes data to the TWI bus.
    // It takes a pointer to the data, and the length of the data.
    // It should loop through the given data and send it on the bus.
    //
    // NB: We need to wait for the write interrupt flag when we are
    //     writing data before we can send the next byte.
}

uint8_t TWI_read_data() {
    // This function reads data from the TWI bus.
    // It should read a byte from the bus and return it.
    //
    // To do this we need to send a read command to the bus.
    // Hint: TWI0.MCTRLB register
    //
    // Then we need to wait on the read interrupt flag.
    //
    // Finally we need to return the data from the data register.
}

void TWI_stop() {
    // This functions sends a stop condition on the TWI bus
    // Hint: TWI0.MCTRLB register
}

void TWI_write_transaction(uint8_t device_address, uint8_t *data, uint16_t len) {
    // A transaction is a complete bus action
    // Then we need to send the address of the device, causing a start condition
    // Then we need to send the data byte(s)
    // Then we need to send a stop condition
}

void TWI_read_transaction(uint8_t device_address, uint8_t *data, uint16_t len) {
    // A transaction is a complete bus action
    // Then we need to send the address of the device, causing a start condition
    // Then we need to send the data byte(s)
    // Then we need to send a stop condition
}