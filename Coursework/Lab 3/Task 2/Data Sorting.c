/******************************************************************************

Your Task:

     Write a program that asks the user to input 4 numbers and displays
     the values in both (a) ascending and (b) descending order.


*******************************************************************************/

#include <stdio.h>

int main() {

    int a, b, c, d, x;

    printf("Please input 4 numbers : \n");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    for (int i = 0; i < 4; i++) {
        if (a > b) { x = a; a = b; b = x; }
        if (b > c) { x = b; b = c; c = x; }
        if (c > d) { x = c; c = d; d = x; }
    }

    printf("In ascending order: %d, %d, %d, %d\n", a, b, c, d);
    printf("In descending order: %d, %d, %d, %d\n", d, c, b, a);

    return 0;
}