#include "vcnl4200.h"
#include "twi.h"
#include <stdint.h>

uint16_t VCNL4200_ReadRegister(uint8_t register_addr) {
    // First we send a write to select the register of interest
    TWI_load_addr(VCNL4200_I2C_ADDRESS, true);
    TWI_write_data((uint8_t[]){register_addr}, 1);

    // Now we start a read, the docs say you should send a TWI stop before
    // but, it did not work for me when I did that. This however, works.
    TWI_load_addr(VCNL4200_I2C_ADDRESS, false);

    // Create a buffer to store the low and high byte of the 16-bit register value
    uint8_t data[2];
    data[0] = TWI_read_data();
    data[1] = TWI_read_data();

    // Send a stop to the I2C bus
    TWI_stop();

    // Combine the low and high byte into a 16-bit value
    uint16_t result = data[0] | (data[1] << 8);

    // Return the result
    return result;
}

void VCNL4200_WriteRegister(uint8_t register_addr, uint16_t value) {
    // Use a union to split the uint16_t into two 8-bit values
    union U16_U8 {
        uint16_t value;
        uint8_t bytes[2];
    };

    // Create a variable with the union type and set the value
    union U16_U8 data;
    data.value = value;

    // Store the data in a command buffer
    uint8_t command[3] = {register_addr, data.bytes[0], data.bytes[1]};

    // Send the write to the device
    TWI_write_transaction(VCNL4200_I2C_ADDRESS, command, 3);
}

void VCNL4200_Init(void) {
    // Enable the proximity sensor
    VCNL4200_WriteRegister(0x03, 0x0000);

    // Enable the ambient light sensor
    VCNL4200_WriteRegister(0x00, 0x0000);
}

void VCNL4200_SetALSIntegrationTime(vcnl4200_als_it_t integration_time) {
    // Read the current register value
    uint16_t current_value = VCNL4200_ReadRegister(0x00);

    // Modify the value to set the integration time
    current_value = (current_value & ~(0b11 << 6)); // Clear the bits we're going to modify
    current_value = current_value | (integration_time << 6); // Set the new value

    // Write the new value
    VCNL4200_WriteRegister(0x00, current_value);
}

void VCNL4200_SetALSPersistance(vcnl4200_als_pers_t persistance) {
    // Read the current register value
    uint16_t current_value = VCNL4200_ReadRegister(0x00);

    // Modify the value to set the peristance
    current_value = (current_value & ~(0b11 << 2)); // Clear the bits we're going to modify
    current_value = current_value | (persistance << 2); // Set the new value

    // Write the new value
    VCNL4200_WriteRegister(0x00, current_value);
}

void VCNL4200_SetProximitySensorIntegrationTime(vcnl4200_ps_it_t integration_time) {
    // Read the current register value
    uint16_t current_value = VCNL4200_ReadRegister(0x03);

    // Modify the value to set the integration time
    current_value = (current_value & ~(0b111 << 1)); // Clear the bits we're going to modify
    current_value = current_value | (integration_time << 1); // Set the new value

    // Write the new value
    VCNL4200_WriteRegister(0x03, current_value);
}

void VCNL4200_SetProximitySensorPersistance(vcnl4200_ps_pers_t persistance) {
    // Read the current register value
    uint16_t current_value = VCNL4200_ReadRegister(0x03);

    // Modify the value to set the peristance
    current_value = (current_value & ~(0b11 << 4)); // Clear the bits we're going to modify
    current_value = current_value | (persistance << 4); // Set the new value

    // Write the new value
    VCNL4200_WriteRegister(0x03, current_value);
}

void VCNL4200_SetProximitySensorDuty(vcnl4200_ps_duty_t duty) {
    // Read the current register value
    uint16_t current_value = VCNL4200_ReadRegister(0x03);

    // Modify the value to set the peristance
    current_value &= ~(0b11 << 6); // Clear the bits we're going to modify
    current_value |= (duty << 6); // Set the new value

    // Write the new value
    VCNL4200_WriteRegister(0x03, current_value);
}

void VCNL4200_SetALSEnable(bool enabled) {
    // Read the current register value
    uint16_t current_value = VCNL4200_ReadRegister(0x00);

    // Modify the value to set the peristance
    if (enabled) {
        current_value &= (1 << 0); // Set the enable bit low to enable
    } else {
        current_value |= ~(1 << 0); // Set the enable bit high to disable
    }

    // Write the new value
    VCNL4200_WriteRegister(0x00, current_value);
}

void VCNL4200_SetProximityEnable(bool enabled) {
    // Read the current register value
    uint16_t current_value = VCNL4200_ReadRegister(0x03);

    // Modify the value to set the peristance
    if (enabled) {
        current_value &= (1 << 0); // Set the enable bit low to enable
    } else {
        current_value |= ~(1 << 0); // Set the enable bit high to disable
    }

    // Write the new value
    VCNL4200_WriteRegister(0x03, current_value);
}

uint16_t VCNL4200_ReadDeviceId(void) {
    return VCNL4200_ReadRegister(0x0E);
}

uint16_t VCNL4200_ReadProximity(void) {
    return VCNL4200_ReadRegister(0x08);
}

uint16_t VCNL4200_ReadAmbientLight(void) {
    return VCNL4200_ReadRegister(0x09);
}