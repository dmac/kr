/* Exercise 2-8. Write a function rightrot(x, n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 */

#include <limits.h>
#include <stdio.h>

void printbits(unsigned char n) {
    int i;
    for (i = CHAR_BIT - 1; i >= 0; i--) {
        printf("%d", (n & 1 << i) >> i);
    }
}

void printintbits(int n) {
    int i;
    for (i = sizeof(n) - 1; i >= 0; i--) {
        printbits(n >> (i * CHAR_BIT));
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int rightrot(int x, int n) {
    int mask = (1 << n) - 1;
    return (x >> n) | ((x & mask) << (sizeof(x) * CHAR_BIT - n));
}

int main(void) {
    printintbits(rightrot(255, 12)); /* 00001111 11110000 00000000 00000000 */
    printintbits(rightrot(85, 8));   /* 01010101 00000000 00000000 00000000 */
}
