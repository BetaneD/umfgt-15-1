// C program to Create a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <c++/v1/ctime>

// Driver code
int main(void)
{
    FILE *fptr = fopen("power_quality_log.csv", "r");

    if (fptr==NULL) {

        printf("ERROR: file unable to open");
        return 1;
    }

    float Time;
    float phase_A;
    float phase_B;
    float phase_C;
    float line_C;
    float frequency;
    float power_f;
    float thd;

    while(fscanf(fptr,"%f %f %f %f %f %f %f %f ",&Time,&phase_A,&phase_B,&phase_C,&line_C,&frequency,&power_f,&thd)==8) {
        printf("Timestamp:\t %.2f, phase_A:\t %.2f, phase_B:\t %.2f, phase_C:\t %.2f, "
                "line_C:\t %.2f, frequency:\t %.2f, power_f:\t %.2f, thd:\t %.2f\n",
                Time,phase_A,phase_B,phase_C,line_C,frequency,power_f,thd);
    }

    fclose(fptr);
    return 0;
}