/* Exercise 3-4. In a two’s complement number representation, our version of
 * itoa does not handle the largest negative number, that is, the value of n
 * equal to −(2^(wordsize−1)). Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c    = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s
 * This handles formatting -INT_MIN. The itoa defined in K&R
 * doesn't work for INT_MIN because in two's complement,
 * -INT_MIN is not a valid int.
 */
void itoa(int n, char s[]) {
    int i, sign;
    if (n == INT_MIN) {
        sign = -1;
        n    = INT_MAX;
    } else if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        if (sign < 0 && n == INT_MAX) {
            s[i++] = n % 10 + '0' + 1;
        } else {
            s[i++] = n % 10 + '0';
        }
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    char s[256];
    itoa(1 << 31, s);
    printf("%s\n%d\n", s, INT_MIN);
}
