/* Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LEN 16

main() {
    int counts[MAX_LEN] = {0};
    int c;
    int len   = 0;
    int state = OUT;
    int i, j;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                ++counts[len];
            }
            state = OUT;
            len   = 0;
        } else {
            state = IN;
            ++len;
        }
    }
    if (len > 0) {
        ++counts[len];
    }
    for (i = 1; i < MAX_LEN; i++) {
        printf("%2d ", i);
        for (j = 0; j < counts[i]; j++) {
            printf("-");
        }
        printf("\n");
    }
}
