/* Exercise 3-3. Write a function expand(s1, s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. Allow for letters of either case and digits, and be
 * prepared to handle cases like a-b-c and a-z0 − 9 and -a-z. Arrange that
 * a leading or trailing - is taken literally.
 */

#include <stdio.h>

int isalphanum(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

void expand(char s1[], char s2[]) {
    int  i, j;
    char c;
    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-' && s1[i] > 0 && s1[i + 1] != '\0' &&
            isalphanum(s1[i - 1]) && isalphanum(s1[i + 1]) && s1[i - 1] < s1[i + 1]) {
            for (c = s1[i - 1] + 1; c < s1[i + 1]; c++) {
                s2[j++] = c;
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

int main(void) {
    char *s1;
    char  s2[256];
    char *tt[] = {
        "az",
        "a-z",
        "-A-Z-",
        "a-c-e",
        "a-z0-9",
    };
    int i;
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        s1 = tt[i];
        expand(s1, s2);
        printf("%s => %s\n", s1, s2);
    }
}
