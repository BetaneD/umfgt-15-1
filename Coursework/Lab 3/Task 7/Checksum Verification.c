/******************************************************************************

Your Task:

     Write a program that takes a three-digit number as input and
     checks if it is an Armstrong number.
     For example, 371 is an Armstrong number because 333 + 777 + 111 = 371.


*******************************************************************************/
#include <stdio.h>

int main() {

    int num, ognum, rem, ans = 0;

    printf("Enter a three-digit integer: ");
    scanf("%d",&num);

    ognum = num;

    while (ognum != 0) {

        rem = ognum % 10;
        ans += rem * rem * rem;
        ognum /= 10;

    }

    if (ans == num){
        printf("\n%d is an Armstrong number.", num);
    }else{
        printf("\n%d is not an Armstrong number.", num);
    }

    return 0;
}