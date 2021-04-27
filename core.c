#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ANNUAL 1
#define QUARTERLY 2
#define MONTHLY 3
#define MAX 10

const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *month_num[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
char *term_name_arr[4] = {"/0", "Annually", "Quarterly", "Monthly"};

int periodInNum(char *term_name)
{
    int term = 0;
    for(int i=1; i <= 3; i++)
    {
        if (strcmp(term_name,term_name_arr[i])==0)
            term = i;
    }
    return term;
}

int countLeapYears(int years, int month)
{
    if (month <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int daysSinceUnixEpoch(int day, int month, int year)
{
    int day_count, epoch_count;
    int epoch_day = 1;
    int epoch_month = 1;
    int epoch_year = 1970;

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
    char month_name[2][4];

    sscanf(d1, "%d-%3s-%d", day + 0, &month_name[0][0], year + 0);
    sscanf(d2, "%d-%3s-%d", day + 1,&month_name[1][0] , year + 1);
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 12; i++)
            if (strcmp(month_name[j], month_num[i]) == 0)
                month_int[j] = i + 1;
        epoch_date[j] = daysSinceUnixEpoch(day[j], month_int[j], year[j]);
    }
    
    return (epoch_date[1] - epoch_date[0]);
}

int calculateInterest(int amount, float roi, int term, int days)
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
