/* Exercise 2-6. Write a function setbits(x, p, n, y) that returns x with the
 * n bits that begin at position p set to the rightmost n bits of y, leaving
 * the other bits unchanged.
 */

#include <stdio.h>

void printbits(unsigned char n) {
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", (n & 1 << i) >> i);
    }
    printf("\n");
}

int setbits(int x, int p, int n, int y) {
    int mask  = (1 << n) - 1;
    int shift = p - n + 1;
    return (x & ~(mask << shift)) | (y & mask) << shift;
}

int main(void) {
    int i;
    struct {
        int x, p, n, y;
    } tt[] = {
        {1, 1, 1, 1},    /* 00000011 */
        {85, 4, 2, 255}, /* 01011101 */
        {255, 6, 3, 0},  /* 10001111 */
        {192, 3, 2, 47}, /* 11001100 */
    };
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        printbits(setbits(tt[i].x, tt[i].p, tt[i].n, tt[i].y));
    }
}
