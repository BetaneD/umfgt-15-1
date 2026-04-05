/******************************************************************************

Your Task:

     Create a program that converts a speed from
     meters per second (m/s) to miles per hour (mph).


*******************************************************************************/


#include <stdio.h>

int main() {

    float speed; // speed input variable

    printf("please input your speed : "); // asks user to input the speed
    scanf("%f",&speed); // inputs speed

    printf("you have input %.2f m/s.\n",speed); // displays speed
    printf("which is %.4f mph.\n ",speed*2.23694); // converts the speed into miles per second

    return 0; // end of code
}