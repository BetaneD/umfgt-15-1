/******************************************************************************

Your Task:

     Write a function called is_even that:
     ◦ Takes one integer as input.
     ◦ Returns 1 (true) if the number is even.
     ◦ Returns 0 (false) if the number is odd.
     ◦ Use this function in main() to print "Even" or "Odd".


*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool is_even(int x){

    return (x % 2) == 0;
}

int main()
{
    int x;

    printf("please input an integer : ");
    scanf("%i",&x);

    int even = is_even(x);

    (even)? printf("\nEven") : printf("\nOdd");

    return 0;
}
