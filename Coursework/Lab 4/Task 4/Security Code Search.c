/******************************************************************************

Your Task:

     ◦ Create an integer array of size 15 with some random numbers,
       making sure the number 42 is included somewhere.
     ◦ Prompt the user to enter the target code to search for.
     ◦ Use a for loop to search for the target in the array.
     ◦ If the target is found, print a message like
       "Access Code Found at Position X" (where X is the index)
       and immediately exit the loop.
     ◦ If the loop finishes without finding the target,
     ◦ print a "Code Not Found" message.


*******************************************************************************/
#include <stdio.h>

int main(){

    int target;
    int code [15]={ 1, 5, -2, 0, 8, -1, 0, 0, 9, -4, 2, 1,42,52,66};
    int found = 0;


    printf("please input your target code : ");
    scanf("%i",&target);

    for (int i = 0 ; i <= 15 ; i++) {

        if (target == code [i]){

            printf("\nAccess Code Found at Position %i",i);

            found++;
            break;
        }
    }

    if (found == 0) printf("\nCode Not Found");

    return 0;
}