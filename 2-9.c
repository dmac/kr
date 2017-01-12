/* Exercise 2-9. In a two’s complement number system, x &= (x − 1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 */

#include <stdio.h>

/* Subtracting 1 from a number will set its rightmost 1-bit to 0 and all the
 * rightmost 0-bits to 1. ANDing this with the original number will not change
 * any of the original rightmost 0-bits (since they're ANDing with 1s), will
 * clear the rightmost 1-bit (because it's ANDing with 0), and leave the
 * remaining bits unchanged.
 *
 *        01101101
 *     -1 01101100
 *     &= 01101100
 *
 *        01101100
 *     -1 01101011
 *     &= 01101000
 */

/* bitcount: count 1 bits in x */
int bitcount(unsigned int x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }
    return b;
}

int bitcountfast(unsigned int x) {
    int b = 0;
    while (x) {
        x &= x - 1;
        b++;
    }
    return b;
}

int main(void) {
    int i, got, want;
    int ns[] = {1, -1, 2, 3, 255, 256, 127, -127};
    for (i = 0; i < sizeof(ns) / sizeof(*ns); i++) {
        got  = bitcountfast(ns[i]);
        want = bitcount(ns[i]);
        if (got != want) {
            printf("fail %d: got %d; want %d\n", ns[i], got, want);
        }
    }
}
