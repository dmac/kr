/* Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

#include <stdio.h>

#define MAX_CHAR 256

main() {
    int counts[MAX_CHAR] = {0};
    int c;
    int i, j;
    while ((c = getchar()) != EOF) {
        ++counts[c];
    }
    for (i = 0; i < MAX_CHAR; i++) {
        printf("%3d %c ", i, i);
        for (j = 0; j < counts[i]; j++) {
            printf("-");
        }
        printf("\n");
    }
}
