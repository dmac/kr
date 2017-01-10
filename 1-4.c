/* Exercise 1-4. Write a program to print the corresponding Celsius to
 * Fahrenheit table.
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = -20, 0, ..., 160; floating-point version */
main() {
    float fahr, celsius;
    int   lower, upper, step;
    lower   = -20; /* lower limit of temperature table */
    upper   = 160; /* upper limit */
    step    = 20;  /* step size */
    celsius = lower;
    printf("  C    F\n");
    printf("----------\n");
    while (celsius <= upper) {
        fahr = celsius * (9.0 / 5.0) + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
