#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dateUtil.h"

#define ANNUAL 1
#define QUARTERLY 2
#define MONTHLY 3
#define MAX 10

char *term_name_arr[4] = {"/0", "Annually", "Quarterly", "Monthly"};

int periodInNum(char *term_name)
{
    int term = 0;
    for(int i=1; i <= 3; i++)
        if (strcmpi(term_name,term_name_arr[i])==0)
            term = i;
    return term;
}

double calculateInterest(double amount, double roi, int term, int days)
{
    double interest = -1;
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
    return interest;
}

double calcTotalOutstanding(double amount, char *date1, char *date2, double payment, double roi, char *period)
{
    int days = dateDifferenceInDays(date1, date2);
    int term = periodInNum(period);
    double interest = calculateInterest(amount, roi, term, days);
    return amount - payment + interest;
}
