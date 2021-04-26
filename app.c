#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "core.h"
#define MAX 100

char *month_numeric[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; //ask

struct Date
{
    int day, month, year;
    char date[15];
    int paidBackAmount, remaining, principalAtTheTime;
};
 

int main()
{
    int  num_test, actual, amount, term, days, payment_made;
    float roi;
    char term_name[10], month_temp[4];
    int remainig[MAX];
    struct Date initial;


    char period[10], money_lender[50], loanee[50];
    system("cls");
    printf("Welcome to RealCost");//Print in center
   
    printf("\nName of money lender:");
    fgets(money_lender, sizeof(money_lender), stdin);
    printf("\nName of loanee or borrower:");
    fgets(loanee, sizeof(loanee), stdin);
    printf("\nEnter the Principal Amount: ");
    scanf("%d", &amount);
    printf("\nEnter the Rate of Interest: ");
    scanf("%f", &roi);
    printf("\nEnter the term of interest application: ");
    scanf("%s", term_name);
    term = periodInNum(term_name);
    printf("\nDate at which loan was given:");
    fflush(stdin);
    fgets(initial.date, sizeof(initial.date), stdin);
    sscanf(initial.date, "%d-%3s-%d", initial.day, month_temp, initial.year);
    printf("\nEnter the number of payment made by the borrower: ");
    scanf("%d", &payment_made);

    struct Date d[payment_made];
    int interest[payment_made];
 
    for (int i = 0; i < 12; i++)
        if (strcmp(month_temp, month_numeric[i]) == 0)
            initial.month = i + 1;

    d[0].day = initial.day; 
    d[0].year = initial.year;
    d[0].principalAtTheTime = amount;
    d[0].paidBackAmount = 0; 
 
    for(int i=1; i<=payment_made; i++ )
    {
        printf("\nDate at which payment %d was made:",i);
        scanf("%s", d[i].date);
        printf("\nAmount of the payment made:");
        scanf("%d",&d[i].paidBackAmount);
        days = dateDifferenceInDays(d[i-1].date, d[i].date);
        interest[i] = calculateInterest(d[i-1].principalAtTheTime, roi, days, term);
        d[i].remaining = d[i-1].principalAtTheTime - d[i].paidBackAmount + interest[i];
        d[i].principalAtTheTime = d[i].remaining;
        printf("%d\n",d[i].remaining);
        printf("%d\n",days);
        //printf()
        
    }


    printf("You have to pay %d as interest.\n", interest);

    return 0;

}

