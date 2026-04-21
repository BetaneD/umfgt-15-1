// C program to Create a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main(void)
{
    FILE *fptr = fopen("power_quality_log.cvs", "r");

    if (fptr==NULL) {

        printf("error");
        return 1;
    }

    char line[256];

    fgets(line,sizeof(line), fptr);

    while(fgets(line, sizeof(line), fptr) != NULL) {

        char *token;

        token = strtok(line,",");
        float Time = atof(token);

        token = strtok(NULL,",");
        float phase_A = atof(token);

        token = strtok(NULL,",");
        float phase_B = atof(token);

        token = strtok(NULL,",");
        float phase_C = atof(token);

        /*token = strtok(NULL,",");
        float line_C = atof(token);

        token = strtok(NULL,",");
        float frequency = atof(token);

        token = strtok(NULL,",");
        float power_f = atof(token);

        token = strtok(NULL,",");
        float thd = atof(token);
        */

        printf ("Timestamp:\t %.2f,phase_A:\t %.2f,phase_B:\t %.2f,phase_C:\t %.2f",
               Time,phase_A,phase_B,phase_C );

    }

    // Close the file
    fclose(fptr);

    return 0;
}