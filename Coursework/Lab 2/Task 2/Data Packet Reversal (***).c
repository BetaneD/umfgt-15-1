/******************************************************************************

Write a C program that:

     ◦ Prompts the user to enter a two-digit number.
     ◦ Reads the number into an int variable.
     ◦ Reverses the digits of the number.
     ◦ Prints the reversed number.


*******************************************************************************/

#include <stdio.h>

int main() {

    int num;
    int ten, one, rev;

    printf("Please enter a two-digit number : ");
    scanf("%d", &num);

    ten = num / 10;
    one = num % 10;

    rev = one * 10 + ten;

    printf("The number reversed is : %d\n", rev);

    return 0;
}