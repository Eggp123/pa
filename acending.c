#include <stdio.h>
#include <stdlib.h>
#include <pic18f452.h>

void main(void) {
    int i, j, temp;
    int num_asc[] = {9, 4, 5};

    for (i = 0; i <= 2; i++) { // point to LHS number
        for (j = i + 1; j <= 2; j++) // point to RHS number
            if (num_asc[i] > num_asc[j]) { // if LHS > RHS , change the position
                temp = num_asc[i];
                num_asc[i] = num_asc[j];
                num_asc[j] = temp;
            }
    }
    TRISB = 0;
    for (i = 0; i <= 2; i++) {
        PORTB = num_asc[i];
    }
}
