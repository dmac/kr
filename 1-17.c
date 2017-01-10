/* Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define PRINTLEN 80  /* print lines longer than this */

int getline2(char line[], int maxline);

main() {
    int  len;
    char line[MAXLINE];
    while ((len = getline2(line, MAXLINE)) > 0) {
        if (len > PRINTLEN) {
            printf("%s", line);
        }
    }
    return 0;
}

/* getline2: read a line into s, return length */
int getline2(char s[], int lim) {
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim) {
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
