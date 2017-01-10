/**/
/* Exercise 1-23. Write a program to remove all comments from a C program.
 * Don’t forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 */
#include <stdio.h>

int main(void) {
    int  in_char    = 0;
    int  in_string  = 0;
    int  in_comment = 0;
    int  check_div  = 0;
    int  escaping   = 0;
    int  c;
    char prev = '\0';
    while ((c = getchar()) != EOF) {
        if (check_div) {
            check_div = 0;
            if (c != '*') {
                printf("/");
            }
        }
        if (in_char) {
            if (escaping) {
                escaping = 0;
            } else if (c == '\\') {
                escaping = 1;
            } else if (c == '\'') {
                in_char = 0;
            }
            goto print;
        }
        if (in_string) {
            if (escaping) {
                escaping = 0;
            } else if (c == '\\') {
                escaping = 1;
            } else if (c == '"') {
                in_string = 0;
            }
            goto print;
        }
        if (!in_comment && !in_string && c == '\'') {
            in_char = 1;
            goto print;
        }
        if (!in_comment && !in_char && c == '"') {
            in_string = 1;
            goto print;
        }
        if (prev == '/' && c == '*') {
            in_comment = 1;
            goto noprint;
        }
        if (prev == '*' && c == '/') {
            in_comment = 0;
            goto noprint;
        }
        if (c == '/') {
            check_div = 1;
            goto noprint;
        }
        if (in_comment) {
            goto noprint;
        }
    print:
        printf("%c", c);
    noprint:
        prev = c;
    }
}

/* test cases */

#define TEST /* asdf */ 1

void testfn(void) {
    int   n = 1 / 2;
    char *s = "test \" \\";
    char  c = '"';  /* test */
    c       = '\''; /* test */
    n++;
    s++;
}
