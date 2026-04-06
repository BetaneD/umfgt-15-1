/******************************************************************************

Your Task:

     ◦ Create an array of 6 chars and initialize it with any characters you like
     (e.g., {'P', 'A', 'C', 'K', 'E','T'}).
     ◦ Use a for loop to print the array elements in reverse order


*******************************************************************************/

#include <stdio.h>

int main(){

    char word[6] ={'E', 'N', 'A', 'T', 'E','B'};

    for (int i = 5 ; i >=0 ; i--){
        printf("%c",word[i]);
    }

    return 0;
}