/******************************************************************************

Write a C program that:

     ◦ Prompts the user to enter a maximum value, X.
     ◦ Generates and prints a random integer between 0 and X (inclusive).



*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int x;

    srand(time(NULL));  // seed with current time

    printf("please enter a maximum value : ");
    scanf("%d",&x);

    printf("%d\n", rand()%(x+1));

    return 0;
}