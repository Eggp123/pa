#include<pic18f4520.h>

void myMsDelay(unsigned int time) // Definition of delay subroutine
{
    unsigned int i, j;
    for (i = 0; i < time; i++) // Loop for time
        for (j = 0; j < 710; j++); // Calibrated for a 1 ms delay in MPLAB
}

void main(void) {
    TRISC = 0x00;
    TRISD = 0x00;
    ADCON1 = 0x0e;
    PR2 = 0xBA;
    CCP1CON = 0x0c;
    T2CON = 0x07;
    PORTD = 0x05;

    while (1) // Endless Loop
    {
        // ----------Duty Cycle 20%-----------
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 1;
        CCPR1L = 0x25;
        // -----------------------------------
        // ----------Duty Cycle 40%-----------
        myMsDelay(2000);
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 0;
        CCPR1L = 0x1B;
        myMsDelay(2000);
        // -----------------------------------
        // ----------Duty Cycle 60%-----------
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 1;
        CCPR1L = 0x70;
        myMsDelay(2000);
        // -----------------------------------
        // ----------Duty Cycle 80%-----------
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 0;
        CCPR1L = 0x96;
        myMsDelay(2000);
        // -----------------------------------
    }
}
