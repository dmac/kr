/* Exercise 3-6. Write a version of itoa that accepts three arguments instead
 * of two. The third argument is a minimum field width; the converted number
 * must be padded with blanks on the left if necessary to make it wide enough.
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

void itoa(int n, char s[], int w) {
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
    for (; i < w; i++) {
        s[i] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    char s[100];
    struct {
        int n, w;
    } tt[] = {
        {10, 0},
        {3, 4},
        {-3, 4},
    };
    int i;
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        itoa(tt[i].n, s, tt[i].w);
        printf("%s\n", s);
    }
}
