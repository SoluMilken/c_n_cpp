#include <stdio.h>

int total_days_in_certain_month(int year, int month)
{   
    int total_days;
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            total_days = 31;
            break;
        case 2:
            if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
                total_days = 29;
            else
                total_days = 28;
            break;
        case 4: case 6: case 9: case 11: 
            total_days = 30;
            break;
        default:
            total_days = 0;
            break;
    }
    return total_days;
}

int check_reasonable_date(int year, int month, int day)
{
    int output, total_days;
    total_days = total_days_in_certain_month(year, month);
    if (month < 1 || month > 12)
        output = -1;
    else if (day < 1 || day > total_days)
        output = -2;
    else
        output = 0;
    return output;
}

int cumulative_days(int year, int month, int day, int first_day_week_number)
{
    int culmulative_days = 0, days, week_number;
    for (int i = 1; i < month; i++)
    {
        days = total_days_in_certain_month(year, i);
        culmulative_days += days;
    }
    culmulative_days += (day - 1);
    week_number = culmulative_days % 7;
    week_number += first_day_week_number;
    week_number = week_number % 7 ;
    return week_number;
}
    
int main(void) 
{
    int year, month,day, first_day_week_number;
    int num_testing_date, i, output, week_number; 
    scanf("%d %d", &year, &first_day_week_number);
    scanf("%d", &num_testing_date);
    
    for (i=1; i<= num_testing_date; i++)
    {
        scanf("%d %d", &month, &day);
        output = check_reasonable_date(year, month, day);
        if (output < 0)
        {
            printf ("%d ", output);
            continue;
        }
        else
        {
            week_number = cumulative_days(year, month, day, first_day_week_number);
            printf("%d ", week_number);
        }
    }
    return 0;
}