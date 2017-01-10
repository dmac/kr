/* Exercise 1-22. Write a program to “fold” long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define FOLDAT 8

int split_and_print_from(char line[], int start, int len);
int getline2(char line[], int maxline);

int main(void) {
    int  len;
    int  start;
    char line[MAXLINE];
    while ((len = getline2(line, MAXLINE)) > 0) {
        if (len < FOLDAT) {
            printf("%s", line);
            continue;
        }
        start = 0;
        while (start != -1) {
            start = split_and_print_from(line, start, len);
        }
    }
}

/* split_and_print_from prints up to FOLDAT characters from start, then a newline.
 * Returns the index of the start of the next line, or -1 if the full
 * line has been printed. */
int split_and_print_from(char line[], int start, int len) {
    int i;
    int last = start;
    for (i = start; i < len; i++) {
        if (i > start + FOLDAT && last > start) {
            break;
        }
        if (line[i] == ' ' && line[i - 1] != ' ' && line[i - 1] != '\t') {
            last = i;
        }
    }
    if (last == start) {
        for (i = start; i < len; i++) {
            printf("%c", line[i]);
        }
        return -1;
    }
    for (i = start; i < last; i++) {
        printf("%c", line[i]);
    }
    printf("\n");
    return last + 1;
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
