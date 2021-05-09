#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int countLeapYears(int years, int month)
{
    if (month <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int daysSinceUnixEpoch(int day, int month, int year)
{
    int day_count, epoch_count;
    const int epoch_day = 1, epoch_month = 1, epoch_year = 1970;

    epoch_count = epoch_year * 365 + epoch_day;
    epoch_count += countLeapYears(epoch_year, epoch_month);

    day_count = year * 365 + day;
    for (int i = 0; i < month - 1; i++)
        day_count += month_days[i];
    day_count += countLeapYears(year, month);

    return (day_count - epoch_count);
}

int dateDifferenceInDays(char *d1, char *d2)
{
    int epoch_date[2];
    int day[2], month_int[2], year[2];

    sscanf(d1, "%d-%d-%d",  year + 0, month_int + 0, day + 0);
    sscanf(d2, "%d-%d-%d",  year + 1, month_int + 1, day + 1);
    for (int j = 0; j < 2; j++)
        epoch_date[j] = daysSinceUnixEpoch(day[j], month_int[j], year[j]);
    return (epoch_date[1] - epoch_date[0]);
}