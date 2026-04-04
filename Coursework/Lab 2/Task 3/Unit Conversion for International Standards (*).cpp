/******************************************************************************

Write a C program that:

     ◦ Prompts the user to enter a speed in mph.
     ◦ Reads the value into a float or double.
     ◦ Converts the speed to km/h (1 mile = 1.60934 kilometers).
     ◦ Displays the result with a clear label.
    
    
*******************************************************************************/

#include <stdio.h> 
 
int main() { 
 
    float speed; // speed input variable 
 
    printf("please input your speed : "); // asks user to input the speed 
    scanf("%f",&speed); // inputs speed 
 
    printf("you have input %.2f mph.\n",speed); // displays speed 
    printf("which is %.4f km/h.\n ",speed*1.60934); // converts the speed into miles per second 
 
    return 0; // end of code 
} 