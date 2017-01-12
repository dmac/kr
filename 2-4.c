/* Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                goto outer;
            }
        }
        s1[j++] = s1[i];
    outer:;
    }
    s1[j] = '\0';
}

int main(void) {
    int  i;
    char buf[32];
    struct {
        char *s1;
        char *s2;
    } tt[] = {
        {"", ""},
        {"abc", ""},
        {"abc", "b"},
        {"abc", "ac"},
        {"abc", "abc"},
    };
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        strcpy(buf, tt[i].s1);
        squeeze(buf, tt[i].s2);
        printf("\"%s\" - \"%s\" = \"%s\"\n", tt[i].s1, tt[i].s2, buf);
    }
}
