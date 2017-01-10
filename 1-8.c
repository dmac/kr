/* Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

main() {
    int c;
    int bc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++bc;
        }
    }
    printf("%d\n", bc);
}
