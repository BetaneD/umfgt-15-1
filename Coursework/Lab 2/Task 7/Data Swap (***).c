/******************************************************************************

Write a C program that:

     ◦ Initializes two integer variables, a and b, to 1 and 2 respectively.
     ◦ Swaps their values.
     ◦ Prints the new values of a and b.


*******************************************************************************/

#include <stdio.h>

int main() {

    int a = 1;
    int b = 2;

    printf("Initial values: a = %d; b = %d\n",a,b);

    const int x = a;
    a = b;
    b = x;

    printf("Swapped values: a = %d; b = %d",a,b);

    return 0;
}