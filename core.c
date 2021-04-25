#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ANNUAL 1
#define QUARTERLY 2
#define MONTHLY 3

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *month_num[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int countLeapYears(int years, int month)
{
    if (month <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int days_since_unix_epoch(int day, int month, int year)
{
    int dayCount, epochCount;
    int epochDay = 1;
    int epochMonth = 1;
    int epochYear = 1970;

    epochCount = epochYear * 365 + epochDay;
    epochCount += countLeapYears(epochYear, epochMonth);

    dayCount = year * 365 + day;
    for (int i = 0; i < month - 1; i++)
        dayCount += monthDays[i];
    dayCount += countLeapYears(year, month);

    return (dayCount - epochCount);
}

int dateDifferenceInDays(char *d1, char *d2) 
{
    int epochD1, epochD2;
    int day[2], month_int[2], year[2];
    char month1_name[4], month2_name[4];

    sscanf(d1, "%d-%3s-%d", day + 0, month1_name, year + 0);
    sscanf(d2, "%d-%3s-%d", day + 1, month2_name, year + 1);

    for (int i = 0; i < 12; i++)
    {
        if (strcmp(month1_name, month_num[i]) == 0)
            month_int[0] = i + 1;
        if (strcmp(month2_name, month_num[i]) == 0)
            month_int[1] = i + 1;
    }
    epochD1 = days_since_unix_epoch(day[0], month_int[0], year[0]);
    epochD2 = days_since_unix_epoch(day[1], month_int[1], year[1]);
    return (epochD2 - epochD1);
}

int calculate_interest(int amount, float roi, int term, int days)
{
    float interest = -1;
    int interest_int;
    switch (term)
    {
    case ANNUAL:
        interest = ((amount * roi * days) / (360 * 100));
        break;
    case QUARTERLY:
        interest = ((amount * roi * days) / (90 * 100));
        break;
    case MONTHLY:
        interest = ((amount * roi * days) / (30 * 100));
        break;
    default:
        printf("\n'Error in interest calculation'\n");
        break;
    }
    interest_int = (int)interest;
    return interest_int;
}
