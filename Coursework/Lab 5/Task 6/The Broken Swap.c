/******************************************************************************

Your Task:

     ◦ Write a function void swap(int a, int b) that attempts to swap the values
       of a and b using a temporary variable.
     ◦ Call it from main() with two variables x = 5 and y = 10.
     ◦ Print x and y after the function call.
     ◦ Observe: Did they swap?


*******************************************************************************/

#include <stdio.h>

void swap(int a, int b){

    const int x = a;
    a = b;
    b = x;

}

int main()
{
    int change = swap (5,10);

    swap();

    printf ("%d",a);
    printf ("%d",b);


    return 0;
}