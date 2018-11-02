/* Exercise 4-13. Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

void reverserec(char s[], int i, int c) {
    char h;
    if (s[i] == '\0') {
        return;
    }
    h = s[i];
    reverserec(s, i + 1, c - 1);
    s[c] = h;
}

void reverse(char s[]) {
    reverserec(s, 0, strlen(s) - 1);
}

int main(void) {
    char *tt[] = {
        "",
        "a",
        "ab",
        "abc",
    };
    char s[100];
    int  i;
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        strcpy(s, tt[i]);
        reverse(s);
        printf("\"%s\" \"%s\"\n", tt[i], s);
    }
}
