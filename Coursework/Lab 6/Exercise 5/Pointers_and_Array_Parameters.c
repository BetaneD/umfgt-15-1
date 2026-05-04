/******************************************************************************

Your Task:

     ◦ Copy and paste the program below into a CLion project.
       The function readarray(int A[], int n) reads values into an array
       from the user. Read this function carefully and make sure you
       understand the syntax. Write a similar function, printarray(),
       which prints the array elements. Test that both functions are working by
       calling them from main().


*******************************************************************************/
#include <stdio.h>

#define ARRAYSIZE 10

int arr1[ARRAYSIZE], arr2[ARRAYSIZE], arr3[ARRAYSIZE];

void readarray(int A[], int n) {

    int i;

    printf("Enter %d integers (separated by spaces) into array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

}

void printarray(int A[], int n) {

    int i;

    printf("The numbers you entered are ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

}

/* Function printarray() goes in here */
int main(void) {


    readarray(arr1, ARRAYSIZE);
    printarray(arr1, ARRAYSIZE);


}
