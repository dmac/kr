/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of
 * itoa; that is, convert an integer into a string by calling a recursive
 * routine.
 */

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

int itoarec(int n, char s[], int i) {
    if (n == 0) {
        return i;
    }
    s[i] = n % 10 + '0';
    return itoarec(n / 10, s, ++i);
}

void itoa(int n, char s[]) {
    int sign, i = 0;
    if ((sign = n) < 0) {
        n = -n;
    }
    i = itoarec(n, s, 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    int tt[] = {
        1,
        23,
        -456,
        789,
        -1011,
    };
    char s[100];
    int  i;
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        itoa(tt[i], s);
        printf("%d %s\n", tt[i], s);
    }
}
