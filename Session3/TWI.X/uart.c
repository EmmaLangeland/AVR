#include "uart.h"

void usart_init(unsigned long baud) {
    TX_PORT.DIRSET = (1 << TX_PIN);

    // Set baud rate we've specified. Note that since the baud rate is usually
    // greater than a value fitting in a 8-bit number, we need to use two
    // registers here
    USART3.BAUD = baud;

    // Enable RX and TX
    USART3.CTRLB = (1 << USART_RXEN_bp) | (1 << USART_TXEN_bp);
}

void usart_transmit(char data) {
    // Sends a character over UART

    // First we should check that there isn't already data being sent.
    // If there is, we should wait for it to finish first
    while (!(USART3.STATUS & (1 << USART_DREIF_bp))) {}

    // Put our new data into TX data register
    USART3.TXDATAL = data;
}

void usart_transmit_string(char *data) {
    // Loop until the end of the string
    while (*data != '\0') {
        usart_transmit(*data);
        data++;
    }
}