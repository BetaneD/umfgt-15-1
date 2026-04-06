/******************************************************************************

Your Task:

     b.& Write a function called power (base, exponent)
       that calculates base^exponent without using the <math.h> library.
     b.& Use a loop inside the function.
     b.& Assume the exponent is a positive integer.
     b.& Return the result.


*******************************************************************************/
#include <stdio.h>

int power (int base, int exponent) {

    int a = base;

    for (int i = 0; i < exponent-1; i++){

        a *= base;
    }
    return a;
}

int main()
{
    int num = power(2,9);

    printf("%d",num);

    return 0;
}



