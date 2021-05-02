#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "core.h"
#include "dateUtil.h"
#define DATESTRLEN 15

void testDaysSinceEpoch(int num, int day, int month, int year, int expected)
{
    int actual = daysSinceUnixEpoch(day, month, year);
    if(expected != actual)
        printf(" UT:daysSinceUnixEpoch - %d Failed ; Expected = %d, Actual = %d \n", num, expected, actual);
    else
        printf(" UT:daysSinceUnixEpoch - %d Passed\n", num);     
}

void runUnitTestsForDaysSinceEpoch()
{
    int testNum = 1;
    testDaysSinceEpoch(testNum++, 1, 1, 2020, 18262);
    testDaysSinceEpoch(testNum++, 15, 2, 2020, 18307);
    testDaysSinceEpoch(testNum++, 18, 3, 2020, 18339);
    testDaysSinceEpoch(testNum++, 13, 9, 2020, 18518);
    testDaysSinceEpoch(testNum++, 17, 11, 2020, 18583);
}

void unitTestSuite()
{
    runUnitTestsForDaysSinceEpoch();
}

void Test_calculate_interest_individual(double amount, double roi, int term, int days, double expected, int test_number)
{ 
    double actual = calculateInterest(amount, roi, term, days);
    if(expected != actual)
        printf(" Test %d Failed, Expected = %lf, Actual = %lf \n",test_number, expected, actual);
    else
        printf(" Test %d Passed\n",test_number);  
}

void Test_calculate_interest()
{
    int term, days, numTest;
    double expected, actual, amount;
    double roi;
    scanf("%d", &numTest);
    for(int test_number = 1; test_number <= numTest; test_number++)
    {
        scanf("%lf",&amount);
        scanf("%lf",&roi);
        scanf("%d",&term);
        scanf("%d",&days);
        scanf("%lf",&expected);
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
            printf(" Test %d Failed, expected_days = %d, actual_days = %d \n",test_number, expected_days, actual_days);
        else
            printf(" Test %d Passed\n", test_number); 
    }
}


void test_app()
{
    int numTest, term;
    double amount, expected_remaining, actual_remaining, interest, paid, roi;
    char date1[DATESTRLEN], date2[DATESTRLEN], term_char[10];
    for(int test_number = 1;  ; test_number++)
    {
        scanf("%lf",&amount);
        if (amount == 0)
            break;
        scanf("%s",date1);
        scanf("%s",date2);
        scanf("%lf",&paid);
        scanf("%lf", &roi);
        roi = roi*100;
        scanf("%s",term_char);
        scanf("%lf", &expected_remaining);
        actual_remaining = calcTotalOutstanding(amount, date1, date2,paid, roi, term_char);
        if(expected_remaining != actual_remaining)
            printf(" Test %d Failed,  expected_remaining = %lf, actual_remaining = %lf  \n",test_number, expected_remaining, actual_remaining);
        else
            printf(" Test %d Passed\n", test_number);
        amount = 0;
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
        else if(strcmp(category,"a")==0)
           test_app();
        else if(strcmp(category,"u")==0)
           unitTestSuite(); 
    }
    return 0;
}
