/* Exercise 1-20. Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop. Assume a fixed
 * set of tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 */

#include <stdio.h>

#define TABWIDTH 4

int main(void) {
    int c;
    int col = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (; col % TABWIDTH != 0; col++) {
                printf("%c", ' ');
            }
        } else {
            printf("%c", c);
            if (c == '\n') {
                col = 0;
            } else {
                ++col;
            }
        }
    }
}
