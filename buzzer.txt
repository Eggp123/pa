#include <pic18f4580.h>

#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT=OFF
#pragma config DEBUG=OFF, LVP=OFF

void msdelay(unsigned int itime);

#define RELAY_PIN PORTBbits.RB4 // PNP transistor connected to RA0

void main() {
    TRISBbits.TRISB4 = 0; // Set RA0 as output for controlling PNP transistor
    RELAY_PIN = 1; // Initially turn off PNP transistor (HIGH = off)

    while (1) {
        RELAY_PIN = 0; // Turn on PNP transistor (LOW = on)
        msdelay(1000); // Delay for 1 second

        RELAY_PIN = 1; // Turn off PNP transistor (HIGH = off)
        msdelay(1000); // Delay for 1 second
    }
}

// Simple delay function

void msdelay(unsigned int itime) {
    int i, j;
    for (i = 0; i < itime; i++)
        for (j = 0; j < 1275; j++);
}
