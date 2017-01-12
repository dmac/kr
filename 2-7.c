/* Exercise 2-7. Write a function invert(x, p, n) that returns x with the n
 * bits that begin at position p inverted (i.e., 1 changed into 0 and vice
 * versa), leaving the others unchanged.
 */

#include <stdio.h>

void printbits(unsigned char n) {
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", (n & 1 << i) >> i);
    }
    printf("\n");
}

int invert(int x, int p, int n) {
    int mask  = (1 << n) - 1;
    int shift = p - n + 1;
    return x ^ (~0 & (mask << shift));
}

int invert2(int x, int p, int n) {
    int mask  = (1 << n) - 1;
    int shift = p - n + 1;
    return (x & ~(mask << shift)) | (~(x & (mask << shift)) & (mask << shift));
}

int main(void) {
    int i;
    struct {
        int x, p, n;
    } tt[] = {
        {8, 3, 2},   /* 00000100 */
        {85, 7, 8},  /* 10101010 */
        {255, 6, 3}, /* 10001111 */
        {0, 5, 6},   /* 00111111 */
    };
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        printbits(invert(tt[i].x, tt[i].p, tt[i].n));
    }
}
