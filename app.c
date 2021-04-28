#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "core.h"
#include "dateUtil.h"

struct Date
{
    char fullDate[15];
    int paidBackAmount, remaining, principalAtTheTime;
};
 

int main()
{
    int  num_test, actual, amount, term, days, payment_made;
    float roi;
    char term_name[10], month_temp[4];
    char period[10], money_lender[50], loanee[50];

    system("cls");
    printf("\n");
    printf("\t\t\t\t\t\t     RealCost");
    
    printf("\n\n Name of money lender: ");
    fgets(money_lender, sizeof(money_lender), stdin);
    printf(" Name of loanee or borrower: ");
    fgets(loanee, sizeof(loanee), stdin);

    printf(" Enter the Principal Amount: ");
    scanf("%d", &amount);
    printf(" Enter the Rate of Interest: ");
    scanf("%f", &roi);
    printf(" Enter the term: ");
    scanf("%s", term_name);
    term = periodInNum(term_name);
    printf(" Enter the number of payment made by the borrower: ");
    scanf("%d", &payment_made);

    struct Date d[payment_made+1];
    int interest[payment_made+1];

    printf(" Date at which loan was given: ");
    scanf("%s", d[0].fullDate);

    
    d[0].principalAtTheTime = amount;
    d[0].paidBackAmount = 0; 
 
    
    printf("\n");
    for(int i=1; i<=payment_made; i++ )
    {
        printf("  Date at which payment %d was made: ",i);
        scanf("%s", d[i].fullDate);
        printf("  Amount of the payment made: ");
        scanf("%d", &d[i].paidBackAmount);
        days = dateDifferenceInDays(d[i-1].fullDate, d[i].fullDate);
        interest[i] = calculateInterest(d[i-1].principalAtTheTime, roi, term, days);
        d[i].remaining = d[i-1].principalAtTheTime - d[i].paidBackAmount + interest[i];
        d[i].principalAtTheTime = d[i].remaining;
        
    }

    system("cls");
    printf("\n");
    printf("\t\t\t\t\t\t     RealCost");
    printf("\n\n Money Lender: %s", money_lender);
    printf(" Loanee: %5s", loanee);

    printf("\n\tPrincipal    Loan Taken On    Paid Back On    Paid Back Amount    Interest        Term    Remaining\n");
    for(int i=1; i<=payment_made; i++ )
        printf("\t%9d%17s%16s%20d%11.2f%c%12s%13d\n", d[i-1].principalAtTheTime, d[i-1].fullDate, d[i].fullDate, d[i].paidBackAmount, roi, '%', term_name, d[i].remaining);
    
    return 0;
}

