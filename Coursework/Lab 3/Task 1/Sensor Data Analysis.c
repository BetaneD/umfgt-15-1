/******************************************************************************

Your Task:

     Write a program that asks the user to input 4 numbers
     and displays the minimum value.


*******************************************************************************/

#include <stdio.h>

int main() {

    int a,b,c,d;
    int f1,f2;

    printf("please input 4 numbers: \n");
    scanf("%i%i%i%i",&a,&b,&c,&d);

    f1 = (a < b) ? a : b;
    f2 = (c < d) ? c : d;
    (f1 < f2) ? printf("the maximum value is %i",f1) : printf("the maximum value is %i",f2);

    return 0;
}