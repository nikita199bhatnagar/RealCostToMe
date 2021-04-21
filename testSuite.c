#include <stdio.h>
#include "core.h"

void Test_calculate_interest_individual(int amount, float roi, int term, int days, int expected, int test_number)
{ 
    int actual = calculate_interest(amount, roi, term, days);
    if(expected != actual)
        printf("Test %d Failed, expected = %d, actual = %d \n",test_number, expected, actual);
    else
        printf("Test %d Passed\n",test_number);  
}

 void Test_calculate_interest(){
    int expected, numTest, actual, amount, term, days;
    float roi;
    scanf("%d",&numTest);
    for(int test_number=1; test_number <= numTest; test_number++)
    {
        scanf("%d",&amount);
        scanf("%f",&roi);
        scanf("%d",&term);
        scanf("%d",&days);
        scanf("%d",&expected);
        Test_calculate_interest_individual(amount, roi, term,  days, expected, test_number);
    }

}
int main()
{
    Test_calculate_interest();
    return 0;
}
