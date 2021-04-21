#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ANNUAL 1
#define QUARTERLY 2
#define MONTHLY 3


int calculate_interest(int amount, float roi, int term, int days)
{
    float interest = -1;
    int interest_int;
    switch(term)
    {
        case ANNUAL:
            interest = ((amount*roi*days)/(360*100));
            break;
        case QUARTERLY: 
            interest = ((amount*roi*days)/(90*100));
            break;
        case MONTHLY: 
            interest = ((amount*roi*days)/(30*100));
            break;
        default:
            printf("\n'Error in interest calculation'\n");
            break;
    }
    interest_int = (int)interest;
    return interest_int;
}


