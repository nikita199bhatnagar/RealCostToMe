//#ifdef
int periodInNum(char *term_name);
int countLeapYears(int years, int month);
int daysSinceUnixEpoch(int day, int month, int year);
int dateDifferenceInDays(char *d1, char *d2);
int calculateInterest(int amount,float roi, int term, int days);
int calcTotalOutstanding(int amount,char *date1,char *date2,int payment,float roi,char *term);