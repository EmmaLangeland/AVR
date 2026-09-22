#ifndef I2C_H
#define I2C_H

#include "stdbool.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>

// Define the TWI frequency
#define TWI_FREQ 100000  // Standard TWI frequency

/**
 * @brief Initializes the TWI (Two Wire Interface) module.
 *
 * This function configures the necessary pins for TWI communication, sets the TWI clock frequency,
 * initializes the address and data registers, sets the bus state to idle, and enables the TWI module.
 *
 * The following steps are performed during initialization:
 * 1. Configures the direction of the TWI pins (SDA and SCL).
 * 2. Enables pull-up resistors on the TWI pins.
 * 3. Sets the TWI clock frequency based on the system clock (F_CPU) and the desired TWI frequency (TWI_FREQ).
 * 4. Initializes the address register to 0x00.
 * 5. Initializes the data register to 0x00.
 * 6. Sets the bus state to idle.
 * 7. Enables the TWI module for operation.
 *
 * @note Ensure that the system clock (F_CPU) and desired TWI frequency (TWI_FREQ) are defined
 *       appropriately before calling this function.
 *
 * @warning This function should be called before any TWI communication is attempted.
 *
 * @example
 * TWI_init(); // Call this function to initialize the TWI module before use
 */
void TWI_init(void);

/**
 * @brief Loads the device address for I2C communication.
 *
 * This function prepares the TWI (Two Wire Interface) to communicate with a specified I2C device
 * by loading the device address into the TWI0 module's address register. The function also sets
 * the read/write mode based on the provided parameter.
 *
 * The device address is shifted left by one bit to make room for the read/write bit, which is
 * set to 0 for write operations and 1 for read operations.
 *
 * @param device_address The 7-bit address of the I2C device (0x00 to 0x7F).
 * @param write A boolean indicating the operation mode:
 *              - true: Write operation
 *              - false: Read operation
 *
 * @note This function waits until the address has been transmitted by checking the write interrupt
 *       flag (TWI_WIF_bm) in the MSTATUS register.
 *
 * @warning Ensure that the TWI0 module is properly initialized before calling this function.
 *
 * @example
 * uint8_t device_addr = 0x50; // Example device address
 * TWI_load_addr(device_addr, true); // Load address for write operation
 */
void TWI_load_addr(uint8_t device_address, bool write);

/**
 * @brief Writes data over the I2C bus.
 *
 * This function transmits a specified number of bytes from a data buffer to the I2C bus.
 * It writes each byte one at a time and waits for the transmission to complete before
 * sending the next byte.
 *
 * @param data Pointer to the data buffer that contains the bytes to be sent.
 * @param len The number of bytes to send from the data buffer.
 *
 * @note The function waits for the write interrupt flag (WIF) to ensure that each byte is
 *       successfully transmitted before proceeding to the next byte. It does not check for
 *       acknowledgment (ACK) from the device after each byte is sent, which may be necessary
 *       for certain applications. Uncomment the ACK check if required.
 *
 * @warning Ensure that the TWI (Two Wire Interface) module is properly initialized before
 *          calling this function. The data buffer must contain at least 'len' bytes of data.
 *
 * @example
 * uint8_t data_to_send[] = {0x01, 0x02, 0x03}; // Data to send
 * uint16_t length = sizeof(data_to_send) / sizeof(data_to_send[0]); // Length of data
 *
 * TWI_write_data(data_to_send, length);
 */
void TWI_write_data(uint8_t *data, uint16_t len);

/**
 * @brief Sends a stop condition on the I2C bus.
 *
 * This function concludes the I2C communication by sending a stop condition.
 * A stop condition indicates to the I2C bus that the current transmission is complete,
 * allowing other devices on the bus to take control.
 *
 * @note This function should be called after completing data transmission or reception
 *       to properly release the bus and signal the end of communication.
 *
 * @warning Ensure that the TWI (Two Wire Interface) module is properly initialized
 *          before calling this function. It is typically called after a series of
 *          read or write operations.
 *
 * @example
 * // After sending or receiving data
 * TWI_stop();
 */
void TWI_stop();

/**
 * @brief Initiates an I2C write transaction to a specified device.
 *
 * This function performs a complete I2C write transaction by starting the 
 * transaction, sending the specified data to the device, and then stopping 
 * the transaction. It is essential for communicating with I2C devices that 
 * require data to be sent to them.
 *
 * @param device_address The 7-bit I2C address of the device to which data 
 *                       will be sent. The address should be left-shifted 
 *                       by one bit (i.e., the least significant bit should 
 *                       be 0 for write operations).
 * @param data          A pointer to the data buffer that contains the data 
 *                      to be sent to the device. The data should be in 
 *                      the format expected by the device.
 * @param len           The number of bytes to send from the data buffer. 
 *                      This should not exceed the maximum data length 
 *                      supported by the device.
 *
 * @note This function assumes that the I2C bus is already initialized and 
 *       that the device is ready to receive data. It is the caller's 
 *       responsibility to ensure that the device is available on the bus 
 *       before calling this function.
 *
 * @warning Ensure that the data buffer is valid and that the length is 
 *          appropriate for the device to avoid communication errors.
 *
 * @example
 * uint8_t device_addr = 0x50; // Example device address
 * uint8_t data_to_send[] = {0x01, 0x02, 0x03}; // Data to send
 * uint16_t length = sizeof(data_to_send); // Length of data
 *
 * // Perform the write transaction
 * TWI_write_transaction(device_addr, data_to_send, length);
 */
void TWI_write_transaction(uint8_t device_address, uint8_t *data, uint16_t len);

#endif // I2C_H
