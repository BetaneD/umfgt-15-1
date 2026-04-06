/******************************************************************************

Your Task:

     ◦ Write a function called add_numbers that:
     ◦ Takes two integers as input arguments.
     ◦ Returns their sum as an integer.
     ◦ In main(), ask the user for two numbers, call your function,
       and print the result.


*******************************************************************************/

#include <stdio.h>

void add_numbers() {

    int x;
    int y;

    printf("please input two numbers :\n");
    scanf("%i%i",&x,&y);

    printf("\n%i + %i = %i ",x,y,x+y);
}

int main()
{
    add_numbers();

    return 0;
}
