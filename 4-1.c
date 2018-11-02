/* Exercise 4-1. Write the function strrindex(s, t), which returns the
 * position of the rightmost occurrence of t in s, or − 1 if there is none.
 */

#include <stdio.h>
#include <string.h>

/* strrindex: return right-most index of t in s, −1 if none */
int strrindex(char s[], char t[]) {
    int i, j, k;
    int slen = strlen(s);
    for (i = slen - 1; i >= 0; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int main(void) {
    struct {
        char *s;
        char *t;
    } tt[] = {
        {"", ""},           /* -1 */
        {"a", "a"},         /* 0 */
        {"ab", "b"},        /* 1 */
        {"abbc", "bb"},     /* 1 */
        {"aabbaacc", "aa"}, /* 4 */
    };
    int i;
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        printf("\"%s\" \"%s\" %d\n", tt[i].s, tt[i].t, strrindex(tt[i].s, tt[i].t));
    }
}
