/******************************************************************************

Write a C program that:

     ◦ Declares an int variable for a sensor ID, a float for a temperature
       reading,and a char for the sensor's status code.
     ◦ Initializes them to 99, 12.34, and 'A' respectively.
     ◦ Prints these values to the screen with descriptive labels


*******************************************************************************/

#include <stdio.h>

int main()
{

    int ID = 99;
    float temp = 12.34;
    char status = 'A';


    printf("sensor ID : %d \n", ID);
    printf("temperature reading : %.2f \n" , temp);
    printf("sensor's status : %c \n", status);


    return 0;
}