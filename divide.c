#include <stdio.h>
#include <stdlib.h>
#include <pic18f452.h>

//Division using successive sustraction

void main(void) {
    //static int v_mem[] = 0x55;       @0x0005
    int dividend, divisor, quotient;
    int result, i;



    dividend = 0x0E;
    divisor = 0x04;
    result = dividend;
    quotient = 0;
    while (1) {
        if (divisor == 0)
            result = 0;
        else if (result < divisor)
            break;
        else {
            result = result - divisor;
            quotient = quotient + 1;
        }
    }
    TRISB = 0;
    PORTB = result; // remainder

    TRISC = 0;
    PORTC = quotient; //quotient

    TRISD = 0;
    PORTD = dividend / divisor;

}
