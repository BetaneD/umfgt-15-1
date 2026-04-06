/******************************************************************************

Your Task:

     Write a program that takes two numbers
     and one of the following operators: +, -, *, /, %, ^.
     It should then perform the requested operation.
     Use switch to handle the different operators.
     The ^ operator can be implemented with the pow() function from <math.h>


*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{
    int x;
    int y;
    char sign;

    printf("please input an operator (+,-,/,%,^) : ");
    scanf("%c",&sign);

    printf("please input a value 1 :");
    scanf("%d",&x);
    printf("please input a value 2 :");
    scanf("%d",&y);

    switch (sign) {
        case '+':
            printf("%d + %d = %d",x,y,x + y);
            break;

        case '-':
            printf("%i - %i = %i",x,y,x - y);
            break;

        case '/':
            printf("%i / %i = %i",x,y,x / y);
            break;

        case '%':
            printf("%i \% %i = %i",x,y,x % y);
            break;

        case '^':
            printf("%i ^ %i = %i",x,y,pow(x,y));
            break;

        default:
            printf("\nplease input an operator");

    }

    return 0 ;
}