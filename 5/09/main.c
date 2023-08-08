#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;
    char *p;

    if (year < 1752 || month < 1 || month > 12 || day < 1)
        return -1;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = daytab[leap];

    if (day > *(p + month))
        return -1;

    for (i = 1; i < month; i++)
        day += *(p + i);

    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    char *p;

    if (year < 1752 || yearday < 1)
        return -1;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = daytab[leap];

    if ((leap && yearday > 366) || (!leap && yearday > 365))
        return -1;

    for (i = 1; yearday > *(p + i); i++)
        yearday -= *(p + i);

    *pmonth = i;
    *pday = yearday;
    return 0;
}

int main() {
    int year = 2023;
    int month = 8;
    int day = 8;
    int yearday = day_of_year(year, month, day);
    if (yearday == -1) {
        printf("Invalid date entered.\n");
        return 1;
    }
    printf("The date %d-%d-%d is the %dth day of the year.\n", year, month, day, yearday);

    int m, d;
    if (month_day(year, yearday, &m, &d) == -1) {
        printf("Invalid day of the year entered.\n");
        return 1;
    }
    printf("The %dth day of the year %d is %d-%d.\n", yearday, year, m, d);

    return 0;
}
