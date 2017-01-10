/* Exercise 1-19. Write a function reverse( s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a
 * time.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline2(char line[], int maxline);
void reverse(char s[]);

main() {
    int  len;
    char line[MAXLINE];
    while ((len = getline2(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
}

/* reverse: destructively reverses the contents of line, excluding a final newline. */
void reverse(char s[]) {
    char c;
    int  i;
    int  len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    if (s[len - 1] == '\n') {
        --len;
    }
    for (i = 0; i < len / 2; ++i) {
        c              = s[i];
        s[i]           = s[len - i - 1];
        s[len - i - 1] = c;
    }
}

/* getline2: read a line into s, return length */
int getline2(char s[], int lim) {
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
