#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ANNUAL 1
#define QUARTERLY 2
#define MONTHLY 3
#define MONTHDEFINE 4
#define DATESTRLEN 15

struct Date
{
    int day, month, year;
    char month_ch[MONTHDEFINE];
    int paidBackAmount, remaining, principalAtTheTime;
};

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


char *month_num[13] 
    = {"/0", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


/*struct Date stringToDate()
{
    char d1[DATESTRLEN];
    struct Date date;
    int day_1, month_1, year_1, day_2, month_2, year_2;
    char month1[MONTHDEFINE], month2[MONTHDEFINE];
    char *token = strtok(d1, "-");
    int temp = 1;
    while (temp <= 3)
    {
        if (temp == 1)
            day_1 = atoi(token);
        else if (temp == 2)
            strcpy(month1, token);
        else if (temp == 3)
            year_1 = atoi(token);
        else
            break;
        token = strtok(NULL, "-");
        temp++;
    }
    date.day = ;

    return date;
}*/

int countLeapYears(int years, int month)
{
    if (month <= 2)
        years--;
 
    return years / 4
           - years / 100
           + years / 400;
}

int dateDifferenceInDays(char *d1, char *d2) //1-Jan-2020 & 15-Feb-2020
{
    int day[2], month_int[2], year[2];
    char month1[MONTHDEFINE], month2[MONTHDEFINE];              
    /*char *d[2];  
    strcpy(d[0],d1);
    strcpy(d[1],d2);
    for (int i = 0; i < 2; i++)
    {
        char *token = strtok(d[i], "-");
        int temp = 1;
        while (token != NULL)
        {
            if (temp == 1)
                day[i] = atoi(token);
            else if (temp == 2)
                strcpy(month[i], token);
            else if (temp == 3)
                year[i] = atoi(token);
            else
                break;
            token = strtok(NULL, "-");
            temp++;
        }
     
        printf("%d\n",day[i]);
        printf("%s\n",month[i]);
        printf("%d\n\n",year[i]);
        
        printf("%d\n\n",i);
    }*/

    char *token1 = strtok(d1, "-");
    int temp = 1;
    while (token1 != NULL)
    {
        if (temp == 1)
            day[0] = atoi(token1);
        else if (temp == 2)
            strcpy(month1, token1);
        else if (temp == 3)
            year[0] = atoi(token1);
        else
            break;
        token1 = strtok(NULL, "-");
        temp++;
    }

    for(int i = 1; i <= 12; i++)
    {
        if (strcmp(month1,month_num[i])==0)
            month_int[0] = i;
    }


    char *token2 = strtok(d2, "-");
    temp = 1;
    while (token2 != NULL)
    {
        if (temp == 1)
            day[1] = atoi(token2);
        else if (temp == 2)
            strcpy(month2, token2);
        else if (temp == 3)
            year[1] = atoi(token2);
        else
            break;
        token2 = strtok(NULL, "-");
        temp++;
    }

    for(int i = 1; i <= 12; i++)
    {
        if (strcmp(month2,month_num[i])==0)
            month_int[1] = i;
    }
    

    
    int firstDayCount, lastDayCount;
    firstDayCount = year[0] * 365 + day[0];
    for (int i = 0; i < month_int[0] - 1; i++)
        firstDayCount += monthDays[i];
 
    firstDayCount += countLeapYears(year[0],month_int[0]);
 
    lastDayCount = year[1] * 365 + day[1];
    for (int i = 0; i < month_int[1] - 1; i++)
        lastDayCount += monthDays[i];
    lastDayCount += countLeapYears(year[1],month_int[1]);
 
    return (lastDayCount - firstDayCount);

}


int calculate_interest(int amount, float roi, int term, int days)
{
    float interest = -1;
    int interest_int;
    switch (term)
    {
    case ANNUAL:
        interest = ((amount * roi * days) / (360 * 100));
        break;
    case QUARTERLY:
        interest = ((amount * roi * days) / (90 * 100));
        break;
    case MONTHLY:
        interest = ((amount * roi * days) / (30 * 100));
        break;
    default:
        printf("\n'Error in interest calculation'\n");
        break;
    }
    interest_int = (int)interest;
    return interest_int;
}
