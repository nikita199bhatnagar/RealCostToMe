#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "core.h"
#include "dateUtil.h"

double roi;
char term_name[10];
int numPayment;

struct Branding
{
    char money_lender[50], loanee[50];
}b1;

struct Date
{
    char fullDate[15];
    double paidBackAmount, remaining, principalAtTheTime;
}d[100];

void print_banner()
{
    system("cls");
    printf("\n");
    printf("\t\t\t\t\t\t     RealCost");
}

void get_branding_info()
{
    printf("\n\n Name of money lender: ");
    fgets(b1.money_lender, sizeof(b1.money_lender), stdin);
    printf(" Name of loanee or borrower: ");
    fgets(b1.loanee, sizeof(b1.loanee), stdin);
}

void print_report()
{
    print_banner();
    printf("\n\n Money Lender: %s", b1.money_lender);
    printf(" Loanee: %5s", b1.loanee);
    printf("\n\tPrincipal    Loan Taken On    Paid Back On    Paid Back Amount    Interest        Term    Remaining\n");
    for(int i=1; i<=numPayment; i++ )
        printf("\t%9.2lf%17s%16s%20.2lf%11.2lf%c%12s%13.2lf\n", d[i-1].principalAtTheTime, d[i-1].fullDate, d[i].fullDate, d[i].paidBackAmount, roi, '%', term_name, d[i].remaining);
    
}

void load_transactions()
{
    d[0].paidBackAmount = 0;
    get_branding_info();
    printf(" Enter the Principal Amount: ");
    scanf("%lf", & d[0].principalAtTheTime);
    printf(" Enter the Rate of Interest: ");
    scanf("%lf", &roi);
    printf(" Enter the term: ");
    scanf("%s", term_name);
    printf(" Enter the number of payment made by the borrower: ");
    scanf("%d", &numPayment);
    printf(" \n[Date Format used is YYYY-MM-DD]\n");
    printf(" Date at which loan was given: ");
    scanf("%s", d[0].fullDate);

    printf("\n");
    for(int i=1; i <= numPayment; i++ )
    {
        printf("  Date at which payment %d was made: ",i);
        scanf("%s", d[i].fullDate);
        printf("  Amount of the payment made: ");
        scanf("%lf", &d[i].paidBackAmount);
        d[i].remaining = calcTotalOutstanding(d[i-1].principalAtTheTime, d[i-1].fullDate, d[i].fullDate, d[i].paidBackAmount, roi, term_name);
        d[i].principalAtTheTime = d[i].remaining;
    }
}

int main()
{
    print_banner();
    load_transactions();
    print_report();
    return 0;
}

