/******************************************************************************

Your Task:

     ◦ Implement and test the following function:


*******************************************************************************/
#include <stdio.h>

// Function implementation
void split_time(long totalsec, int *hr, int *min, int *sec) { // receives the adresses for the hours, minutes and seconds as arguments

    *hr = (int)(totalsec / 3600);// divides seconds by how many sconds in an hour

    long secleft = totalsec % 3600; // revmoves the hours

    *min = (int)(secleft / 60);// divides by how many seconds in a minute

    *sec = (int)(secleft % 60); // takes the remainder for the seconds
}

int main() {
    long seconds = 100; // seconds input
    int h, m, s; // initializes the variable for h,m,s

    split_time(seconds, &h, &m, &s);//what ever value is held at h,m,s is replaced by the pointers given value in the function

    printf("Total seconds: %ld\n", seconds); //prints seconds variable
    printf("Split time: %d hours, %d minutes, %d seconds\n", h, m, s); // prints value at h,m,s

    return 0;
}
