/******************************************************************************

Your Task:

     ◦ Create an integer array of size 12 and initialize it
       with a mix of positive, negative, and zerovalues
       (e.g., 1, 5, -2, 0, 8, -1, 0, 0, 9, -4, 2, 1).
     ◦ Use a for loop to iterate through the array.
     ◦ Inside the loop, use if-else if-else statements to check if
       the current element is positive, negative, or zero.
     ◦ Use three separate counter variables
       (positiveCount, negativeCount, zeroCount) to keep track of the totals.
     ◦ After the loop, print the final counts for each category.


*******************************************************************************/

#include <stdio.h>

int main() {

    float code[12] ={1, 5, -2, 0, 8, -1, 0, 0, 9, -4, 2, 1} ;

    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    for (int i = 0 ; i < 12 ; i++){

        if (0 < code[i]) positiveCount++;
        if (0 > code[i]) negativeCount++;
        if (0 == code[i]) zeroCount++;
    }
    printf("the number of positive numbers is %i\n",positiveCount);
    printf("the number of negative numbers is %i\n",negativeCount);
    printf("the number of zeros is %i\n",zeroCount);

    return 0;
}
