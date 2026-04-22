 // C program to Create a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Waveform_struct.h"

// Driver code
int main(void)
{
int rows = 0;
    int i = 0;

    FILE *fptr = fopen("power_quality_log.csv", "r");

    if (fptr==NULL) {

        printf("error");
        return 1;
    }

    char line[256];

    fgets(line,sizeof(line), fptr);

    while (fgets(line, sizeof(line), fptr) != NULL) {
        rows++;
    }
    printf("Number of rows: %d\n\n", rows);

    Waveform *data = malloc(rows * sizeof(Waveform));

    if (data == NULL) {
        printf("Error allocating memory: Check malloc\n");
        fclose(fptr);
        return 1;
    }

    rewind(fptr);
    fgets(line, sizeof(line), fptr);

    while(fgets(line, sizeof(line), fptr) != NULL) {

        char *token;

        token = strtok(line,",");
          if (token) data[i].timestamp = atof(token);

        token = strtok(NULL,",");
          if (token) data[i].phase_A = atof(token);

        token = strtok(NULL,",");
          if (token) data[i].phase_B = atof(token);

        token = strtok(NULL,",");
          if (token) data[i].phase_C = atof(token);

        token = strtok(NULL,",");
          if (token) data[i].line_C = atof(token);

        token = strtok(NULL,",");
          if (token) data[i].frequency = atof(token);

        token = strtok(NULL,",");
          if (token) data[i].power_f = atof(token);

        token = strtok(NULL,",");
          if (token) data[i].thd = atof(token);

    i++;
    }

  for (int j = 0; j < rows; j++) {
    printf("Timestamp: %.2f | phase_A: %.2f | phase_B: %.2f | phase_C: %.2f | Line_C: %.2f | Frequency: %.2f | Power_F: %.2f | THD: %.2f\n",
           data[j].timestamp,
           data[j].phase_A,
           data[j].phase_B,
           data[j].phase_C,
           data[j].line_C,
           data[j].frequency,
           data[j].power_f,
           data[j].thd
           );
  }


  free(data);


    fclose(fptr);

    return 0;
}