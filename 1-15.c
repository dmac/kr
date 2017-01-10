/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
 */

#include <stdio.h>

float fahr_to_celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

main() {
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, fahr_to_celsius(fahr));
}
