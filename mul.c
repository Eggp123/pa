#include <stdio.h>
#include <stdlib.h>
#include <pic18f452.h>

//multiplication using successive addition

void main(void) {
    int num1, num2;
    int result, i;

    result = 0;
    num1 = 0x23;
    num2 = 0x10;

    for (i = 1; i <= num2; i++) {
        result = result + num1;
    }

    TRISB = 0;
    PORTB = result;

    TRISC = 0;
    PORTC = num1*num2;

}
