/******************************************************************************

Write a C program that:

     ◦ Prompts the user to enter the height and length of a right-angled triangle.
     ◦ Calculates the hypotenuse using the Pythagorean theorem (sqrt() function
       from <math.h>).
     ◦ Calculates and displays the perimeter and area of the triangle.


*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {

    float a, b;

    printf("please enter the adjecent length:");
    scanf("%f", &a);
    printf("please enter the opposite length:");
    scanf("%f", &b);

    printf("the hypotenuses length is :%.3f \n",sqrt((a*a)*(b*b)));

    return 0;


}
