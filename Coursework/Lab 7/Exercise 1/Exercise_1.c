/******************************************************************************

Your Task:

     ◦ Declare structure variables c1, c2 and c3, each having members real and imaginary
       of type double.

     ◦ Modify the declaration in part (a) so that c1’s members initially have the values 0.0 and 1.0,
       while c2’s members are 1.0 and 0.0 initially (c3 is not initialised).

     ◦ Write statements that copy the members of c2 into c1. Can this be done in one statement
       or does it require two?

     ◦ Write statements that add the corresponding members of c1 and c2 storing the result in
       c3.


*******************************************************************************/
#include <stdio.h>

typedef struct{
    double c1;
    double c2;
    double c3;
}Complex;

int main()
{
    struct var v1 = {1.0,0.0,1.0};

    printf("c1 = %0.1f",v1.c1);

    return 0;
}