/******************************************************************************

Your Task:

     ◦ Copy and paste the program below into a new CLion project and run it.
       Study the program and carefully note down the output at each step.
     ◦ The program contains two sections which are commented out.
     ◦ Try to run the program with each of these sections re-instated
       (one at a time).
     ◦ What happens in each case?
     ◦ Can you explain why?


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){

    int x1 = 10, x2 = 20, x3; // initalising variable
    int *ptr1, *ptr2, *ptr3; // declaring pointers

    printf("Addresses of x1, x2, x3: %p %p %p\n\n", &x1, &x2, &x3);//showing the Addresses of the variables
    printf("Press Enter to continue......");
    getchar(); //pauses the program until enter is pressed


    /* BAD
    printf(" Object pointed to by uninitialised ptr1 = %d\n", *ptr1);
    printf("Press Enter to continue......");
    getchar();
    */


    ptr1 = &x1; // pointer stores the adress of x1

    printf("ptr1 now holds the address:%p\n\n", ptr1); // prints x1 adress
    printf("Value pointed to by ptr1= %d\n\n", *ptr1); // print value held in x1
    printf("Press Enter to continue......");
    getchar(); //pauses the program until enter is pressed

    ptr2 = ptr1; // pointer stores the same address held at ptr1

    printf("Value pointed to by ptr2 = %d\n\n", *ptr2);// print value held in x1


    /* BAD
    *ptr3 = 99;
    */


    ptr2 = &x2; // pointer stores the adress of x2
    ptr3 = &x3; // pointer stores the adress of x3
    *ptr3 = *ptr1 + *ptr2; // the values held at the address ptr1 and 2 store is added and then is put into the variable that ptr3 hold the address

    printf("New value of x3 = %d\n\n", x3);// prints x1+x2 value

    return 0;
}