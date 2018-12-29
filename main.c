#include <stdio.h>

int main() {
    
    char *months[] = {
        "January", "Febrauary",
        "March", "April",
        "May", "June",
        "July", "August",
        "September", "October",
        "November", "December"
    };
    int days_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int d,m,y;
    
    printf("Enter the date month and year in the format dd mm yyyy\n");
    scanf("%d%d%d", &d, &m, &y);
    
    long int total_days = (y-1)*365L;
    int leap_days = (y-1)/4 - (y-1)/100 + (y-1)/400;
    total_days += leap_days;
    
    if((y%4 == 0) && ( y%100 != 0 || y%400 == 0)) {
        days_month[1]+=1;
    }
    int month = m;
    while(month-->0) {
        total_days += days_month[month-1];
    }

    int day = total_days % 7;
    printf("\n\t%d\t%s\t%d\t\n\n",d,months[m-1], y);
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    int days_counter = 1;
    for(int j=1; j<=day; j++) {
        printf("\t");
        days_counter++;
    }
    printf("\t");
    for(int j=1; j<=days_month[m-1];j++) {
        days_counter++;
        if(days_counter <= 7) {
            printf("%d\t",j);
        } else {
            printf("\n%d\t",j);
            days_counter = 1;
        }
    }
    printf("\n\n");
}