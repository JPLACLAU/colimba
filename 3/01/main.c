#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high && v[mid = (low + high) / 2] != x) {  /* the second arguments means x is not "found yet" */
        if (x < v[mid])
            high = mid - 1; /* it erases the whole high section with no x */
        else
            low = mid + 1; /* it erases the whole low section with no x */
    }
    if(v[mid] == x)  /* checking for a match outside the loop */
        return mid;
    else
        return -1; /* no match */
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; /*  array to search */
    int x = 7; /* number to find */

    /* There is an alternative version with user prompt for x value on this directory */

    int n = 10;  /*  size of array */
    int index = binsearch(x, v, n);
    if (index != -1)
        printf("Found %d at index %d\n", x, index);
    else
        printf("Did not find %d\n", x);
    return 0;
}
