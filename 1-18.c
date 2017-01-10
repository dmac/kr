/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline2(char line[], int maxline);
int trimr(char line[], int len);

main() {
    int  len;
    char line[MAXLINE];
    while ((len = getline2(line, MAXLINE)) > 0) {
        len = trimr(line, len);
        if (len > 1 || (len == 1 && line[0] != '\n')) {
            printf("%s", line);
        }
    }
}

/* trimr: destructively modifies line by removing trailing tabs and spaces
          and returns the new length
 */
int trimr(char line[], int len) {
    int nl = 0;
    --len;
    if (line[len] == '\n') {
        --len;
        nl = 1;
    }
    while (len >= 0 && (line[len] == ' ' || line[len] == '\t')) {
        --len;
    }
    ++len;
    if (nl) {
        line[len] = '\n';
        ++len;
    }
    line[len] = '\0';
    return len;
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
