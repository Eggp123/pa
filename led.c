#include <PIC18f452.h>

#pragma config WDT = OFF    
#pragma config LVP = OFF    

#define LED PORTAbits.RA6    // Define RB0 as the LED pin

void msdelay(unsigned int time); // Delay function prototype

void main(void) {
    TRISAbits.TRISA6 = 0; // Set RB0 as output (LED pin)

    while (1) {
        LED = 1; // Turn LED on
        msdelay(25); // Delay for 500ms
        LED = 0; // Turn LED off
        msdelay(25); // Delay for 500ms
    }
}

void msdelay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 710; j++);
    }
}
