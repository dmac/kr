/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>

#define MAXUTYPE(type) ((unsigned type)(-1))
#define MAXSTYPE(type) ((1UL << (sizeof(type) * CHAR_BIT - 1)) - 1)
#define MINSTYPE(type) ((type)~MAXSTYPE(type))

int main(void) {
    printf("char:\n");
    printf("    smin: %d %d\n", MINSTYPE(char), CHAR_MIN);
    printf("    smax: %ld %d\n", MAXSTYPE(char), CHAR_MAX);
    printf("    umax: %u %u\n", MAXUTYPE(char), UCHAR_MAX);

    printf("short:\n");
    printf("    smin: %d %d\n", MINSTYPE(short), SHRT_MIN);
    printf("    smax: %ld %d\n", MAXSTYPE(short), SHRT_MAX);
    printf("    umax: %u %u\n", MAXUTYPE(short), USHRT_MAX);

    printf("int:\n");
    printf("    smin: %d %d\n", MINSTYPE(int), INT_MIN);
    printf("    smax: %ld %d\n", MAXSTYPE(int), INT_MAX);
    printf("    umax: %u %u\n", MAXUTYPE(int), UINT_MAX);

    printf("long:\n");
    printf("    smin: %ld %ld\n", MINSTYPE(long), LONG_MIN);
    printf("    smax: %ld %ld\n", MAXSTYPE(long), LONG_MAX);
    printf("    umax: %lu %lu\n", MAXUTYPE(long), ULONG_MAX);

    printf("long:\n");
    printf("    smin: %ld %ld\n", MINSTYPE(long), LONG_MIN);
    printf("    smax: %ld %ld\n", MAXSTYPE(long), LONG_MAX);
    printf("    umax: %lu %lu\n", MAXUTYPE(long), ULONG_MAX);

    printf("float:\n");
    printf("    min mag: %g\n", FLT_MIN);
    printf("    max mag: %g\n", FLT_MAX);

    printf("double:\n");
    printf("    min mag: %g\n", DBL_MIN);
    printf("    max mag: %g\n", DBL_MAX);
}
