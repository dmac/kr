/* Exercise 2-10. Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

/* int lower(int c) {
 *     if (c >= ′A′ && c <= ′Z′)
 *         return c + ′a′ - ′A′;
 *     else return c;
 * }
 */

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int main(void) {
    char *s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int   i;
    for (i = 0; s[i] != '\0'; i++) {
        printf("%c", lower(s[i]));
    }
    printf("\n");
}
