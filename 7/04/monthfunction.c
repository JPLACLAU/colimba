#include <stdio.h>

int main() {
    int day, month, year;
    char *months[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };


    printf("Enter a date (example, 22/8/2023): ");
    if (scanf("%d/%d/%d", &day, &month, &year) == 3) {
        if (month >= 1 && month <= 12) {
            printf("%d of %s %d\n", day, months[month-1], year);
        } else {
            printf("Invalid month entered.\n");
        }
    } else {
        printf("Invalid date format entered.\n");
    }

    return 0;
}
