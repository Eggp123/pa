#include <pic18f4550.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char string1[] = "\n\rPREC Loni";
unsigned char string2[] = "\n\rUSART Test Code";
unsigned char string3[] = "\n\rSend 10 characters to uC\n\r";
unsigned char string4[] = "\n\rTransmitted Characters are:";
unsigned char string5[] = "\n\rRx Tx test complete\n\r";

void TXbyte(unsigned char data);
void TXstring(unsigned char *string);

void main() {
    unsigned char i;
    unsigned char rx_data[20];

    TRISCbits.TRISC7 = 1; // RX pin input
    TRISCbits.TRISC6 = 0; // TX pin output

    // Correct Baud Rate Settings for 9600bps at 48MHz
    SPBRGH = 0x04;
    SPBRG = 0xE1;
    BAUDCONbits.BRG16 = 1; // 16-bit Baud Rate generator
    TXSTAbits.BRGH = 1; // High speed
    TXSTAbits.TXEN = 1; // Enable transmitter
    RCSTAbits.SPEN = 1; // Enable serial port
    RCSTAbits.CREN = 1; // Enable receiver

    TXstring(string1);
    TXstring(string2);
    TXstring(string3);

    for (i = 0; i < 10; i++) {
        while (!PIR1bits.RCIF); // Wait for data
        rx_data[i] = RCREG; // Read received character
    }

    rx_data[10] = '\0'; // End of string

    TXstring(string4);
    TXstring(rx_data);
    TXstring(string5);

    while (1); // Infinite loop
}

void TXbyte(unsigned char data) {
    while (!TXSTAbits.TRMT); // Wait till transmit buffer empty
    TXREG = data; // Send data
}

void TXstring(unsigned char *string) {
    while (*string != '\0') {
        TXbyte(*string);
        string++;
    }
}
