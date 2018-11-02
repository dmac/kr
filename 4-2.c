/* Exercise 4-2. Extend atof to handle scientific notation of the form
 * 123.45e−6 where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>

/* atof: convert string s to double */
double atof(char s[]) {
    double val, power;
    int    i, sign, exp, expsign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] != 'E' && s[i] != 'e') {
        return sign * val / power;
    }
    i++;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (exp = 0; isdigit(s[i]); i++) {
        exp = 10.0 * exp + (s[i] - '0');
    }
    return sign * val / power * pow(10, exp * expsign);
}

int main(void) {
    struct {
        char *s;
    } tt[] = {
        {"123"},
        {"123.456"},
        {"123.45e-6"},
        {"123.45E-3"},
        {"123.45E3"},
    };
    int i;
    for (i = 0; i < sizeof(tt) / sizeof(*tt); i++) {
        printf("\"%s\" %f\n", tt[i].s, atof(tt[i].s));
    }
}
