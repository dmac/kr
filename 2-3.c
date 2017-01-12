/* Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <stdio.h>

int htoi(char *s) {
    int n   = 0;
    int len = 0;
    int i;
    while (s[len] != '\0') {
        len++;
    }
    if (len >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        s += 2;
        len -= 2;
    }
    for (i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - '0');
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + (s[i] - 'a' + 10);
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A' + 10);
        } else {
            return -1;
        }
    }
    return n;
}

int main(void) {
    printf("%8s %8d\n", "1", htoi("1"));
    printf("%8s %8d\n", "a", htoi("a"));
    printf("%8s %8d\n", "A", htoi("A"));
    printf("%8s %8d\n", "10", htoi("10"));
    printf("%8s %8d\n", "1b", htoi("1b"));
    printf("%8s %8d\n", "0XFF", htoi("0XFF"));
    printf("%8s %8d\n", "0xff", htoi("0xff"));
}
