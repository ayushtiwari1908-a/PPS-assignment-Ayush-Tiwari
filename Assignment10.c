#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;
    int days[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    char *months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    char *weekdays[] = {
        "Sun", "Mon", "Tue", "Wed",
        "Thu", "Fri", "Sat"
    };

    struct tm date = {0};
    time_t timestamp;
    int first_day;

    printf("Enter year: ");
    scanf("%d", &year);

    if (year < 1 || year > 9999)
    {
        printf("Invalid year!\n");
        return 1;
    }

   
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        days[1] = 29;
    }

   
    date.tm_year = year - 1900;
    date.tm_mon = 0;
    date.tm_mday = 1;
    date.tm_isdst = -1;

    timestamp = mktime(&date);

    if (timestamp == (time_t)-1)
    {
        printf("Unable to calculate calendar.\n");
        return 1;
    }

    first_day = date.tm_wday;

    for (month = 0; month < 12; month++)
    {
        printf("\n\n       %s %d\n", months[month], year);

        for (int i = 0; i < 7; i++)
            printf("%5s", weekdays[i]);

        printf("\n");

        for (int i = 0; i < first_day; i++)
            printf("     ");

       
        for (day = 1; day <= days[month]; day++)
        {
            printf("%5d", day);

            if ((first_day + day) % 7 == 0)
                printf("\n");
        }

        printf("\n");

       
        first_day = (first_day + days[month]) % 7;
    }

    return 0;
