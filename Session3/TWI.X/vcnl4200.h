#ifndef VCNL4200_H
#define VCNL4200_H

#include <stdint.h>
#include "twi.h"

// Device datasheet:
// https://www.vishay.com/docs/84430/vcnl4200.pdf

// Typedefs shamelessly borrowed from the Adafruit driver
// This driver can be found at https://github.com/adafruit/Adafruit_VCNL4200/tree/main

// ALS Integration Time settings
/**
 * @brief Enumeration for ALS integration time settings.
 */
 typedef enum {
    VCNL4200_ALS_IT_50MS = 0x00,  ///< 50 ms integration time
    VCNL4200_ALS_IT_100MS = 0x01, ///< 100 ms integration time
    VCNL4200_ALS_IT_200MS = 0x02, ///< 200 ms integration time
    VCNL4200_ALS_IT_400MS = 0x03  ///< 400 ms integration time
  } vcnl4200_als_it_t;
  
  // ALS Persistence settings
  /**
   * @brief Enumeration for ALS persistence settings.
   */
  typedef enum {
    VCNL4200_ALS_PERS_1 = 0x00, ///< ALS persistence 1 conversion
    VCNL4200_ALS_PERS_2 = 0x01, ///< ALS persistence 2 conversions
    VCNL4200_ALS_PERS_4 = 0x02, ///< ALS persistence 4 conversions
    VCNL4200_ALS_PERS_8 = 0x03  ///< ALS persistence 8 conversions
  } vcnl4200_als_pers_t;
  
  // Proximity Sensor Integration Time settings
  /**
   * @brief Enumeration for Proximity Sensor integration time settings.
   */
  typedef enum {
    VCNL4200_PS_IT_1T = 0x00, ///< Proximity integration time 1T
    VCNL4200_PS_IT_2T = 0x01, ///< Proximity integration time 2T
    VCNL4200_PS_IT_3T = 0x02, ///< Proximity integration time 3T
    VCNL4200_PS_IT_4T = 0x03, ///< Proximity integration time 4T
    VCNL4200_PS_IT_8T = 0x04, ///< Proximity integration time 8T
    VCNL4200_PS_IT_9T = 0x05  ///< Proximity integration time 9T
  } vcnl4200_ps_it_t;
  
  // Proximity Sensor Persistence settings
  /**
   * @brief Enumeration for Proximity Sensor persistence settings.
   */
  typedef enum {
    VCNL4200_PS_PERS_1 = 0x00, ///< Proximity persistence 1 conversion
    VCNL4200_PS_PERS_2 = 0x01, ///< Proximity persistence 2 conversions
    VCNL4200_PS_PERS_3 = 0x02, ///< Proximity persistence 3 conversions
    VCNL4200_PS_PERS_4 = 0x03  ///< Proximity persistence 4 conversions
  } vcnl4200_ps_pers_t;
  
  // Proximity Sensor Duty settings
  /**
   * @brief Enumeration for Proximity Sensor duty cycle settings.
   */
  typedef enum {
    VCNL4200_PS_DUTY_1_160 = 0x00, ///< Proximity duty cycle 1/160
    VCNL4200_PS_DUTY_1_320 = 0x01, ///< Proximity duty cycle 1/320
    VCNL4200_PS_DUTY_1_640 = 0x02, ///< Proximity duty cycle 1/640
    VCNL4200_PS_DUTY_1_1280 = 0x03 ///< Proximity duty cycle 1/1280
  } vcnl4200_ps_duty_t;

// VCNL4200 I2C address
#define VCNL4200_I2C_ADDRESS 0x51

// Function prototypes
/**
 * @brief Reads a 16-bit value from a specified register of the VCNL4200 sensor.
 *
 * @param register_addr The address of the register to read from.
 * @return uint16_t The 16-bit value read from the specified register.
 */
uint16_t VCNL4200_ReadRegister(uint8_t register_addr);

/**
 * @brief Writes a 16-bit value to a specified register of the VCNL4200 sensor.
 *
 * @param register_addr The address of the register to write to.
 * @param value The 16-bit value to write to the specified register.
 */
void VCNL4200_WriteRegister(uint8_t register_addr, uint16_t value);

/**
 * @brief Initializes the VCNL4200 sensor by enabling the proximity and ambient light sensors.
 */
void VCNL4200_Init(void);

/**
 * @brief Sets the ambient light sensor integration time.
 *
 * @param integration_time The integration time to set for the ambient light sensor.
 */
void VCNL4200_SetALSIntegrationTime(vcnl4200_als_it_t integration_time);

/**
 * @brief Sets the ambient light sensor persistence.
 *
 * @param persistance The persistence setting to apply to the ambient light sensor.
 */
void VCNL4200_SetALSPersistance(vcnl4200_als_pers_t persistance);

/**
 * @brief Sets the proximity sensor integration time.
 *
 * @param integration_time The integration time to set for the proximity sensor.
 */
void VCNL4200_SetProximitySensorIntegrationTime(vcnl4200_ps_it_t integration_time);

/**
 * @brief Sets the proximity sensor persistence.
 *
 * @param persistance The persistence setting to apply to the proximity sensor.
 */
void VCNL4200_SetProximitySensorPersistance(vcnl4200_ps_pers_t persistance);

/**
 * @brief Sets the duty cycle for the proximity sensor.
 *
 * @param duty The duty cycle setting to apply to the proximity sensor.
 */
void VCNL4200_SetProximitySensorDuty(vcnl4200_ps_duty_t duty);

/**
 * @brief Enables or disables the ambient light sensor.
 *
 * @param enabled A boolean value indicating whether to enable (true) or disable (false) the ambient light sensor.
 */
void VCNL4200_SetALSEnable(bool enabled);

/**
 * @brief Enables or disables the proximity sensor.
 *
 * @param enabled A boolean value indicating whether to enable (true) or disable (false) the proximity sensor.
 */
void VCNL4200_SetProximityEnable(bool enabled);

/**
 * @brief Reads the device ID of the VCNL4200 sensor.
 *
 * @return uint16_t The device ID of the VCNL4200 sensor.
 */
uint16_t VCNL4200_ReadDeviceId(void);

/**
 * @brief Reads the proximity value from the VCNL4200 sensor.
 *
 * @return uint16_t The proximity value read from the sensor.
 */
uint16_t VCNL4200_ReadProximity(void);

/**
 * @brief Reads the ambient light value from the VCNL4200 sensor.
 *
 * @return uint16_t The ambient light value read from the sensor.
 */
uint16_t VCNL4200_ReadAmbientLight(void);


#endif // VCNL4200_H