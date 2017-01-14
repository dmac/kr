/* Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with
 * only one test inside the loop and measure the difference in run-time.
 */

#include <assert.h>
#include <stdio.h>
#include <time.h>

/* binsearch: find x in v[0] < = v[1] < = ... < = v[n−1] */
int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low  = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

int binsearch_fast(int x, int v[], int n) {
    int low, high, mid;
    low  = 0;
    high = n - 1;
    while (low < high - 1 && v[low] != x && v[mid] != x && v[high] != x) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid;
    }
    if (v[low] == x) {
        return low;
    } else if (v[high] == x) {
        return high;
    } else {
        return -1; /* no match */
    }
}

int main(void) {
    int     arr[100];
    int     len = sizeof(arr) / sizeof(*arr);
    int     i;
    clock_t start;
    for (i = 0; i < len; i++) {
        arr[i] = i;
    }

    start = clock();
    for (i = 0; i < 10000000; i++) {
        binsearch(i % len, arr, len);
    }
    printf("%ld\n", clock() - start);

    start = clock();
    for (i = 0; i < 10000000; i++) {
        binsearch_fast(i % len, arr, len);
    }
    printf("%ld\n", clock() - start);
}
