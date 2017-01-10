/* Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define TABWIDTH 4

int main(void) {
    int c, i;
    int spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++spaces;
            continue;
        }
        for (i = 0; i < spaces / TABWIDTH; ++i) {
            printf("\t");
        }
        for (i = 0; i < spaces % TABWIDTH; ++i) {
            printf(" ");
        }
        printf("%c", c);
        spaces = 0;
    }
}
