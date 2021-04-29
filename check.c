#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "core.h"
#include "dateUtil.h"
#define DATESTRLEN 15

int main()
{
    int numTest, amount, expected_remaining, expected_days, actual_days, actual_remaining, interest, term, paid;
    float roi;
    char date1[DATESTRLEN], date2[DATESTRLEN], term_char[10], testCase[60], garbage;
    scanf("%d",&numTest);
    printf("%d", numTest);
    fflush(stdin);
    fgets(testCase, sizeof(testCase), stdin);
    printf("%s", testCase);

}