#include <stdio.h>


int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2; /* the search begins at half of the array */

        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else  /* This is the line of match found, when x=v[mid] */
        /* mid is a number that changes every loop until it is found to be equal to x */
            return mid;
    }
    return -1; /* no match, this line is to prevent bugs */
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; /*  array to search */
    int x; /* number to find */

    printf("Enter value to search (must be from 1 to 10):");
    scanf("%d%*c", &x);

    int n = 10; /*  size of array */
    int index = binsearch(x, v, n);
    if (index != -1)
        printf("Found %d at index %d\n", x, index);
    else
        printf("Did not find %d\n", x);
    return 0;
}
