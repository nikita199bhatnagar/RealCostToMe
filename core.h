//#ifdef
int periodInNum(char *term_name);
int countLeapYears(int years, int month);
int daysSinceUnixEpoch(int day, int month, int year);
int dateDifferenceInDays(char *d1, char *d2);
double calculateInterest(double amount,double roi, int term, int days);
double calcTotalOutstanding(double amount, char *date1, char *date2, double payment, double roi, char *term);