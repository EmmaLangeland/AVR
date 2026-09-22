#ifndef I2C_H
#define I2C_H

#include "stdbool.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>

// Define the TWI frequency
#define TWI_FREQ 100000  // Standard TWI frequency
#define F_CPU 4000000UL

/*
 * TWI (Two Wire Interface) Implementation
 * 
 * This module provides functions to initialize and manage TWI communication
 * with devices. It includes functions for loading device addresses, writing
 * and reading data, and handling transactions.
 */

 // Initializes the TWI interface and sets up the necessary configurations.
void TWI_init();

// Loads the device address into the TWI address register.
void TWI_load_addr(uint8_t device_address, bool write); 

// Writes a specified length of data to the TWI bus.
void TWI_write_data(uint8_t *data, uint16_t len);

// Reads a byte of data from the TWI bus.
uint8_t TWI_read_data();

// Sends a stop condition on the TWI bus.
void TWI_stop();

// Performs a write transaction to a specified device.
void TWI_write_transaction(uint8_t device_address, uint8_t *data, uint16_t len); 

// Performs a read transaction from a specified device.
void TWI_read_transaction(uint8_t device_address, uint8_t *data, uint16_t len);

#endif // I2C_H
