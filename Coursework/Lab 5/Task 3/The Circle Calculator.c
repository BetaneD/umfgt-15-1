/******************************************************************************

Your Task:

     b.& Write two functions:
     b.& calculate_circumference(radius): Returns 2 * PI * r
     b.& calculate_area(radius): Returns PI * r^2
     b.& Use const double PI = 3.14159;
     b.& The radius should be a double.
     b.& The return values should be double.


*******************************************************************************/

#include <stdio.h>
#include <math.h>

double calculate_circumference(double radius) {

    const double PI = 3.14159;
    return 2 * PI * radius;
}


double calculate_area(double radius) {

    const double PI = 3.14159;

    return PI * pow(radius, 2);
}


int main()
{
    double circumference = calculate_circumference(10);
    double area = calculate_area(10);

    printf("the cirmuference is %.3lf\n",circumference);
    printf("the area is %.3lf\n",area);

    return 0;
}
