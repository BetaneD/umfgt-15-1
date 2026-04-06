/******************************************************************************

Your Task:

      ◦ Declare and initialize an array of 8 floats with the following values:
        88.5, 92.1, 85.0, 95.3, 89.9, 91.2, 84.8, 90.5.
      ◦ Use a loop to traverse the array and find the minimum and maximum values.
      ◦ Calculate the sum of all values and then compute the average.
      ◦ Print the min, max, and average values to the screen.


*******************************************************************************/

#include <stdio.h>

int main() {

    float temp[8] ={88.5, 92.1, 85.0, 95.3, 89.9,91.2, 84.8, 90.5} ;

    float max = temp[1];
    float min = temp[1];
    float average;

    for (int i = 0 ; i < 8 ; i++){

        if (max <= temp[i]) max = temp[i];
        if (min >= temp[i]) min = temp[i];

        average += temp[i];

    }

    average /=8;

    printf("the max number is %.2f\n",max);
    printf("the min number is %.2f\n",min);
    printf("the average is %.2f\n",average);

    return 0;
}