/* Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

main() {
    int c = 0;
    printf("%d\n", c == EOF);
    c = EOF;
    printf("%d\n", c == EOF);
}
