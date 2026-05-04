/******************************************************************************

Your Task:

     ◦ Copy and paste the program below into a new project.
     ◦ Add code where indicated to print the addresses of the
       local variables x and y in functions foo1() and foo2() respectively.
     ◦ Study the program carefully.
     ◦ What do you notice when you run the program?
     ◦ Can you explain this?
     ◦ Now reinstate the function foo3() and its call from main()
       and run the program again.
     ◦ Try to explain the program output.


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void foo1(int xval){

    int x;
    x = xval;
    /* print the address of x here – “The address of x is ..” */

    printf("The address of x is : %p\n",&x);
}

void foo2(int yval){

    int y;
    y = yval;

    /* print the address of y here – “The address of y is..” */
    printf("The address of y is : %p\n",&y);
}

void foo3(void){
    int z;
    foo1(z);
}


int main(void){

    foo1(7);// calls the function and then returns it
    foo2(11);// calls funtion to the same place as it is cleared then returns it
    foo3(); // address by x and y is used by int z so another adress is used for x when it is called
    system("PAUSE");

    // when running the program without foo 3 x and y are at the same address
    // when running through program with foo 3 it print what is in foo 1 but the adress of x is different
    return 0;
}