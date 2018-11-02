/* Exercise 4-14. Define a macro swap(t, x, y) that interchanges two arguments
 * of type t. (Block structure will help.)
 */

#include <stdio.h>

#define SWAP(t, x, y) \
    do {              \
        t tmp = (x);  \
        (x)   = (y);  \
        (y)   = tmp;  \
    } while (0)

int main(void) {
    int  na = 1;
    int  nb = 2;
    char ca = 'a';
    char cb = 'b';
    SWAP(int, na, nb);
    printf("%d %d\n", na, nb);
    SWAP(int, ca, cb);
    printf("%c %c\n", ca, cb);
}
