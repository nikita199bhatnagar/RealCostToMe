#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "core.h"
#define DATESTRLEN 15

void Test_calculate_interest_individual(int amount, float roi, int term, int days, int expected, int test_number)
{ 
    int actual = calculateInterest(amount, roi, term, days);
    if(expected != actual)
        printf("Test %d Failed, expected = %d, actual = %d \n",test_number, expected, actual);
    else
        printf("Test %d Passed\n",test_number);  
}

void Test_calculate_interest()
{
    int expected, numTest, actual, amount, term, days;
    float roi;
    scanf("%d", &numTest);
    for(int test_number = 1; test_number <= numTest; test_number++)
    {
        scanf("%d",&amount);
        scanf("%f",&roi);
        scanf("%d",&term);
        scanf("%d",&days);
        scanf("%d",&expected);
        Test_calculate_interest_individual(amount, roi, term,  days, expected, test_number);
    }
}

void Test_date_difference()
{
    int expected_days, numTest, actual_days;
    char d1[DATESTRLEN], d2[DATESTRLEN];
    scanf("%d",&numTest);
    for(int test_number = 1; test_number <= numTest; test_number++)
    {
        scanf("%s %s %d", d1, d2, &expected_days);
        actual_days = dateDifferenceInDays(d1, d2);
        if(expected_days != actual_days)
            printf("Test %d Failed, expected_days = %d, actual_days = %d \n",test_number, expected_days, actual_days);
        else
            printf("Test %d Passed\n", test_number); 
    }
}

int main(int argc, char *argv[])
{
   if(argc > 1)
   {
       char *category = argv[1];
       if(strcmp(category,"i")==0)
            Test_calculate_interest();

       else if(strcmp(category,"d")==0)
            Test_date_difference();
    }
    return 0;
}
