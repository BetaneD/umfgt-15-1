//
// Created by Fatima Daudi on 25/04/2026.
//

#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Waveform* csv_open(int *rows) {
    int i = 0;

    FILE *fptr = fopen("power_quality_log.csv", "r");

    if (fptr==NULL) {
        printf("ERROR OPENING FILE: check csv file\n");
        exit(1);
    }

    char line[256];

    fgets(line,sizeof(line), fptr);

    while (fgets(line, sizeof(line), fptr) != NULL) {
        (*rows)++;
    }
    printf("Number of rows: %d\n\n", rows);

    Waveform *data = malloc(rows * sizeof(Waveform));

    if (data == NULL) {
        printf("ERROR ALLOCATING MEMORY: Check malloc\n");
        fclose(fptr);
        exit (1);
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
    
    fclose(fptr);
    return data;
}

void csv_close () {

    free(data);

    fclose(fptr);
}