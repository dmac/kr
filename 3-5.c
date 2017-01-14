/* Exercise 3-5. Write the function itob(n, s, b) that converts the integer n
 * into a base b character representation in the string s. In particular,
 * itob(n, s, 16) formats n as a hexadecimal integer in s.
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c    = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b) {
    char *alphabet =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int i, sign;
    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = alphabet[n % b];
    } while ((n /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    char s[100];
    struct {
        int n, b;
    } tt[] = {
        {255, 10},
        {255, 16},
        {-255, 16},
        {128, 16},
        {85, 2},
    };
    int i;
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        itob(tt[i].n, s, tt[i].b);
        printf("%s\n", s);
    }
}
