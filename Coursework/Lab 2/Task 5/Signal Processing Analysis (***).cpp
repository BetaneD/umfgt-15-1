/******************************************************************************

Write a C program that:

     ◦ Prompts the user to enter a start value for x and an interval.
     ◦ Calculates f(x) for the start value and for three subsequent steps
       (start + interval, start + 2*interval, etc.).
     ◦ Displays the results in a formatted table as shown below.


*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{

    float start;
    float interval;
    float fx;
    const double PI = 3.14159265;


    printf("please a start number: ");
    scanf("%f", &start);

    printf("please an interval number: ");
    scanf("%f", &interval);

    printf("\nValue of x\tValue of f(x)\n");


    for (int i = 0; i < 4; i++) {

        fx = 2*sin(PI*start) + 3*cos(PI*start);

        printf("%.2f", start);
        printf("\t\t%.4f\n", fx);

        start += interval;

    }

    return 0;
}
