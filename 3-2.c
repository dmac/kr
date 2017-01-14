/* Exercise 3-2. Write a function escape(s, t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies
 * the string t to s. Use a switch. Write a function for the other direction as
 * well, converting escape sequences into the real characters.
 */

#include <stdint.h>
#include <stdio.h>

void escape(char s[], char t[]) {
    int si, ti;
    for (si = 0, ti = 0; t[ti] != '\0'; ti++) {
        switch (t[ti]) {
        case '\n':
            s[si++] = '\\';
            s[si++] = 'n';
            break;
        case '\t':
            s[si++] = '\\';
            s[si++] = 't';
            break;
        default:
            s[si++] = t[ti];
            break;
        }
    }
    s[si] = '\0';
}

void unescape(char s[], char t[]) {
    int si, ti;
    int escaped = 0;
    for (si = 0, ti = 0; t[ti] != '\0'; ti++) {
        switch (t[ti]) {
        case '\\':
            if (escaped) {
                s[si++] = t[ti];
                escaped = 0;
            } else {
                escaped = 1;
            }
            break;
        case 'n':
            if (escaped) {
                s[si++] = '\n';
                escaped = 0;
            } else {
                s[si++] = t[ti];
            }
            break;
        case 't':
            if (escaped) {
                s[si++] = '\t';
                escaped = 0;
            } else {
                s[si++] = t[ti];
            }
            break;
        default:
            s[si++] = t[ti];
            break;
        }
    }
    s[si] = '\0';
}

int main(void) {
    char *t = "abc\ndef\tghi";
    char  s1[1000];
    char  s2[1000];
    escape(s1, t);
    printf("%s\n-------------\n%s\n", t, s1);
    printf("\n");
    unescape(s2, s1);
    printf("%s\n-------------\n%s\n", s1, s2);
}
