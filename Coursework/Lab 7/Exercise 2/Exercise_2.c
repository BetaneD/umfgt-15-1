/******************************************************************************

Your Task:

     ◦ Write a function which asks for a user’s date of birth and calculates
     how old they are in years, months, and days.
     The function must use a suitable structure as input and return a struct as an output.
     (hint: use ctime from time.h).


*******************************************************************************/
#include <stdio.h>
#include <time.h>

typedef  struct {
    int y;
    int m;
    int d;
}birthday;

int main()
{
    time_t curtime;

    time(&curtime);

    int day,day2;
    int month,month2;
    int year,year2;

    printf("what day were u born?\t");
    scanf("%i",&day);

    printf("what month were u born?\t");
    scanf("%i",&month);

    printf("what year were u born?\t");
    scanf("%i",&year);

    birthday bday1 = {day,month,year};

    printf("what day is it today?\t");
    scanf("%i",&day2);

    printf("what month is it today?\t");
    scanf("%i",&month2);

    printf("what year is it today?\t");
    scanf("%i",&year2);

    birthday bday2 = {day2,month2,year2};
    birthday bday3 = {day2,month2,year2};



    printf("\nur birthday is the %i %i %i",bday1.d,bday1.m,bday1.y);




    return 0;
}