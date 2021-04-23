#include <stdio.h>
#include "core.h"

int main()
{
    int numTest, interest, amount, term, days;
    float roi;
    printf("\nEnter the principal amount:");
    scanf("%d",&amount);
    printf("\nEnter the Rate of Interest:");
    scanf("%f",&roi);
    printf("\nEnter the term of interest application:");
    scanf("%d",&term);
    printf("\nEnter the number of days between the payments:");
    scanf("%d",&days);

    interest = calculate_interest(amount, roi, term, days);
    printf("You have to pay %d as interest.\n", interest);

    return 0;
}
