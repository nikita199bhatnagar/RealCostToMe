#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ANNUAL 1
#define QUARTERLY 2
#define MONTHLY 3
#define MAX 10

char *term_name_arr[4] = {"/0", "Annually", "Quarterly", "Monthly"};

int periodInNum(char *term_name)
{
    int term = 0;
    for(int i=1; i <= 3; i++)
        if (strcmp(term_name,term_name_arr[i])==0)
            term = i;
    return term;
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
