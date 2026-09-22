#ifndef UART_H
#define UART_H

#define F_CPU 4000000UL

#include <avr/io.h>

// This is a pre-calculated baud value for 9600 baud
// Using this would make your life much easier.
#define BAUD_9600         4 * F_CPU / 9600

// PORT and PIN that the UART TX is on
#define TX_PORT           PORTB
#define TX_PIN            0

/**
 * @brief Initializes the USART with the specified baud rate.
 *
 * This function configures the USART peripheral for communication at the
 * specified baud rate. It sets the direction of the TX pin and enables
 * both the transmitter and receiver.
 *
 * @param baud The desired baud rate for USART communication.
 *             This value should be set according to the communication
 *             requirements of the application.
 * @return void
 */
void usart_init(unsigned long baud);

/**
 * @brief Transmits a single character over UART.
 *
 * This function sends a single character through the USART. It first checks
 * if the USART is ready to transmit data by waiting for the Data Register
 * Empty flag to be set. Once ready, it writes the character to the TX data
 * register.
 *
 * @param data The character to be transmitted.
 * @return void
 */
void usart_transmit(char data);

/**
 * @brief Transmits a null-terminated string over UART.
 *
 * This function sends a string of characters through the USART. It loops
 * through each character in the string until it reaches the null terminator,
 * calling the usart_transmit function for each character.
 *
 * @param data Pointer to a null-terminated string to be transmitted.
 * @return void
 */
void usart_transmit_string(char *data);



#endif // UART_H
