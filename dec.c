#include <stdio.h>
#include <stdlib.h>
#include <pic18f452.h>

void main(void) {
    int i, j, temp;
    int num_desc[] = {7, 2, 5, 1, 6};

    // Sorting the array in descending order
    for (i = 0; i <= 4; i++) { // Point to the LHS number
        for (j = i + 1; j <= 4; j++) { // Point to the RHS number
            // If LHS < RHS, swap to sort in descending order
            if (num_desc[i] < num_desc[j]) {
                temp = num_desc[i];
                num_desc[i] = num_desc[j];
                num_desc[j] = temp;
            }
        }
    }

    TRISB = 0; // Set PORTB as output

    // Display sorted numbers on PORTB
    for (i = 0; i <= 4; i++) {
        PORTB = num_desc[i];
    }
}
