#include <stdio.h>

/* printd: book provided */
void printd(int n) {
    if(n < 0) {
        putchar('-');
        n = -n;
    }
    if(n / 10)
        printd(n / 10); /*We call printd with n divided by 10 until n is less than 10. This is a recursion */
    putchar(n % 10 + '0');
}

/* swap: book provided */
void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort: book provided */
void qsort(int v[], int left, int right) {
    int i, last;
    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1); /* here we have another recursion to look for the left part of the array v */
    qsort(v, last + 1, right); /* same as before, but for the right part */
}

int main() {
    int n = -1234;
    printd(n);
    putchar('\n');

    int v[] = {3, 1, 4, 7, 5, 9, 2, 6, 8};
    int len = sizeof(v) / sizeof(int);
    qsort(v, 0, len - 1);  /* sorts v into increasing order */


    for(int i = 0; i < len; i++) {
        printd(v[i]);
        putchar(' ');
    }
    putchar('\n');

    return 0;
}
