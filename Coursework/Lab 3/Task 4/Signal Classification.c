/******************************************************************************

Your Task:

     Using the switch statement,
     write a program that converts a numerical grade into
     a letter grade based on the scale:
     A (80-100),
     B (60-79),
     C (40-59),
     D (30-39),
     F (<30).
     Print an error for inputs outside 0-100.


*******************************************************************************/

#include <stdio.h>

int main()
{
    int grade;
    printf("please input a grade : ");
    scanf("%d",&grade);

    int input = grade / 10;

    switch (input) {
        case 3:
            printf("Grade D");
            break;
        case 4:
            printf("Grade C");
            break;
        case 5:
            printf("Grade C");
            break;
        case 6:
            printf("Grade B");
            break;
        case 7:
            printf("Grade B");
            break;
        case 8:
            printf("Grade A");
            break;
        case 9:
            printf("Grade A");
            break;
        case 10:
            printf("Grade A");
            break;

        default:
            printf("Grade F");

    }
    return 0 ;
}