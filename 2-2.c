/* Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||.
 */

/* for (i = 0; i < lim − 1 && (c = getchar()) != ′\n′ && c != EOF; ++i)
 *     s[i] = c;
 */

#include <stdio.h>

#define MAXLINE 1000

int main(void) {
    int  i, c;
    int  lim = MAXLINE;
    char s[MAXLINE];
    for (i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (c == EOF) {
            break;
        }
        s[i] = c;
    }
    printf("%s\n", s);
}
