/******************************************************************************

Your Task:

     Write a C program that declares an array of 10 doubles.
     Use a for loop to initialize all elements of the array to -1.0.
     Finally, use another for loop to print all the elements
     to verify they have been set correctly.


*******************************************************************************/

#include <stdio.h>

int main() {

    float temp[8] ={88.5, 92.1, 85.0, 95.3, 89.9,91.2, 84.8, 90.5} ;

    float max = temp[1];
    float min = temp[1];

    for (int i = 0 ; i < 8 ; i++){

        if (max <= temp[i]) max = temp[i];
        if (min >= temp[i]) min = temp[i];
    }

    printf("the max number is %.2f\n",max);
    printf("the min number is %.2f\n",min);

    return 0;
}