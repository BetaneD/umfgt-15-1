#include "io.h"
#include "waveform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Waveform* csv_open(int *rows, const char *filename) {
    int i = 0;

    FILE *fptr = fopen(filename, "r");

    if (fptr==NULL) {
        printf("ERROR OPENING FILE: check csv file\n");
        exit(1);
    }

    char line[256];

    fgets(line,sizeof(line), fptr);

    while (fgets(line, sizeof(line), fptr) != NULL) {
        (*rows)++;
    }

    Waveform *data = malloc((*rows) * sizeof(Waveform));

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

void print_data_A(int rows, Waveform *data, FILE *fp) {

  if (fp == NULL) {
    printf("ERROR OPENING FILE: check csv file\n");
    exit(1);
  }

  ///// PHASE A /////
  fprintf(fp,"\t---PHASE A---");

  double phase_A_rms = rms_A(rows, data);
  fprintf(fp,"\n\n the RMS of phase A is %.2lf", phase_A_rms);

  bool toleranceA = tolerance_check(230,10,phase_A_rms);
    if (toleranceA) {
        fprintf(fp,"\n In tolerance : YES");
    } else {
        fprintf(fp,"\n In tolerance : NO");
    }

  double amplitudeA = amplitude_A(rows,data);
  fprintf(fp,"\n the amplitude of phase A is %.2lf", amplitudeA);

  int count = 0;
  double* clippingA = Detect_clipping_A(324.9, rows, data, &count);

    if (count == 0) {
        fprintf(fp, "\n clipping not detected");
    } else {
        fprintf(fp, "\n clipping detected at timestamp :\n");
        for (int i = 0; i < count; i++) {
            fprintf(fp, "\n %lf", clippingA[i]);
        }
    }

  double DC_offsetA = DC_offset_A(rows,data);
  fprintf(fp,"\n\n the DC offset of phase A is %.2lf", DC_offsetA);

    double VarianceA = variance_A(rows,data);
    fprintf(fp,"\n the variance of phase A is %.2lf", VarianceA);

    double STDEVA = STDEV_A(rows,VarianceA);
    fprintf(fp,"\n the STDEV of phase A is %.2lf", STDEVA);

    free(clippingA);

}

void print_data_B(int rows, Waveform *data, FILE *fp) {

  if (fp == NULL) {
    printf("ERROR OPENING FILE: check csv file\n");
    exit(1);
  }

  ///// PHASE B /////
  fprintf(fp,"\n\n\t---PHASE B---");

  double phase_B_rms = rms_B(rows, data);
  fprintf(fp,"\n\n the RMS of phase B is %.2lf", phase_B_rms);

  bool toleranceB = tolerance_check(230,10,phase_B_rms);
    if (toleranceB) {
        fprintf(fp,"\n In tolerance : YES");
    } else {
        fprintf(fp,"\n In tolerance : NO");
    }

  double amplitudeB = amplitude_B(rows,data);
  fprintf(fp,"\n the amplitude of phase B is %.2lf", amplitudeB);

  int count = 0;
  double* clippingB = Detect_clipping_B(324.9, rows, data, &count);

    if (count == 0) {
        fprintf(fp, "\n clipping not detected");
    } else {
        fprintf(fp, "\n clipping detected at timestamp :\n");
        for (int i = 0; i < count; i++) {
            fprintf(fp, "\n %lf", clippingB[i]);
        }
    }

  double DC_offsetB = DC_offset_B(rows,data);
  fprintf(fp,"\n\n the DC offset of phase B is %.2lf", DC_offsetB);

    double VarianceB = variance_B(rows,data);
    fprintf(fp,"\n the variance of phase B is %.2lf", VarianceB);

    double STDEVB = STDEV_B(rows,VarianceB);
    fprintf(fp,"\n the STDEV of phase B is %.2lf", STDEVB);

    free(clippingB);
}

void print_data_C(int rows, Waveform *data, FILE *fp) {

    if (fp == NULL) {
        printf("ERROR OPENING FILE: check csv file\n");
        exit(1);
    }

  ///// PHASE C /////
  fprintf(fp,"\n\n\t---PHASE C---");

  double phase_C_rms = rms_C(rows, data);
    fprintf(fp,"\n\n the RMS of phase B is %.2lf", phase_C_rms);

  bool toleranceC = tolerance_check(230,10,phase_C_rms);
    if (toleranceC) {
        fprintf(fp,"\n In tolerance : YES");
    } else {
        fprintf(fp,"\n In tolerance : NO");
    }

  double amplitudeC = amplitude_C(rows,data);
    fprintf(fp,"\n the amplitude of phase B is %.2lf", amplitudeC);

    int count = 0;
    double* clippingC = Detect_clipping_C(324.9, rows, data, &count);

    if (count == 0) {
        fprintf(fp, "\n clipping not detected");
    } else {
        fprintf(fp, "\n clipping detected at timestamp :\n");
        for (int i = 0; i < count; i++) {
            fprintf(fp, "\n %lf", clippingC[i]);
        }
    }

  double DC_offsetC = DC_offset_C(rows,data);
    fprintf(fp,"\n\n the DC offset of phase C is %.2lf", DC_offsetC);

  double VarianceC = variance_C(rows,data);
    fprintf(fp,"\n the variance of phase C is %.2lf", VarianceC);

  double STDEVC = STDEV_C(rows,VarianceC);
    fprintf(fp,"\n the STDEV of phase C is %.2lf", STDEVC);

    free(clippingC);

}

void print_sort(int rows, Waveform *data, FILE *fp) {
    if (fp == NULL) {
        printf("ERROR OPENING FILE: check csv file\n");
        exit(1);
    }

    ///// PHASE C /////
    fprintf(fp,"\n\n\t---Value sorted by magnitude---");

    double* sortA = insertionSort_A(rows,data);
    double* sortB = insertionSort_A(rows,data);
    double* sortC = insertionSort_A(rows,data);

    for (int i = 0; i < rows; i++)
    {
        fprintf(fp,"\n phase_A: %.2lf | phase_B: %.2lf | phase_C: %.2lf",
        sortA[i],
        sortB[i],
        sortC[i]
        );

    }
    printf("\n");
    free(sortA);
    free(sortB);
    free(sortC);

}


void csv_close(Waveform *data) {
    if (data != NULL) {
        free(data);
    }
}