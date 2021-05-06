#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "core.h"
#include "dateUtil.h"
#define DATESTRLEN 15


int main(int argc, char *argv[])
{
    double amount = atof(argv[1]);
    double roi = atof(argv[2]);
    int term = atoi(argv[3]);
    int days = atoi(argv[4]);
    double actual = calculateInterest(amount, roi, term, days);
    printf("%lf",actual);
    return 0;
}