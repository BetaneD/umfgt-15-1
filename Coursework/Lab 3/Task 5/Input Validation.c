/******************************************************************************

Your Task:

     Write a program that takes a user's input.
     If it's between -10 and 10,
     it should output (a) whether the value is positive, negative, or zero,
     and (b) whether it is odd or even.
     If the input is outside the range,
     it should print an error message.


*******************************************************************************/

#include <stdio.h>

int main() {

    int value;

    printf("please input a value : ");
    scanf("%d",&value);

    if (value <= 10 && value >= -10) {

        if (value > 0) {
            printf("\nthe value is positive");
        } else if (value < 0) {
            printf("\nthe value is negative");
        } else {
            printf("\nThe value is 0");
        }

    } else {

        printf("\nERROR please input number within range");
    }
    return 0 ;
}