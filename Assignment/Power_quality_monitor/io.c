//
// Created by Fatima Daudi on 25/04/2026.
//

#include "io.h"
#include "waveform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Waveform* csv_open(int *rows) {
    int i = 0;

    FILE *fptr = fopen("../power_quality_log.csv", "r");

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

  double toleranceA = tolerance_check(rows,230,10,phase_A_rms);
  fprintf(fp,"\n the tolerance of phase A is %.2lf", toleranceA);

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

    double meanA = mean_A(rows,data);

    double VarianceA = variance_A(rows,data, meanA);
    fprintf(fp,"\n the variance of phase A is %.2lf", VarianceA);

    double STDEVC = STDEV_C(rows,VarianceA);
    fprintf(fp,"\n the STDEV of phase A is %.2lf", STDEVC);

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

  double toleranceB = tolerance_check(rows,230,10,phase_B_rms);
  fprintf(fp,"\n the tolerance of phase B is %.2lf", toleranceB);

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

    double meanB = mean_B(rows,data);

    double VarianceB = variance_A(rows,data, meanB);
    fprintf(fp,"\n the variance of phase B is %.2lf", VarianceB);

    double STDEVC = STDEV_C(rows,VarianceB);
    fprintf(fp,"\n the STDEV of phase B is %.2lf", STDEVC);
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

  double toleranceC = tolerance_check(rows,230,10,phase_C_rms);
    fprintf(fp,"\n the tolerance of phase C is %.2lf", toleranceC);

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

  double meanC = mean_C(rows,data);

  double VarianceC = variance_A(rows,data, meanC);
    fprintf(fp,"\n the variance of phase C is %.2lf", VarianceC);

  double STDEVC = STDEV_C(rows,VarianceC);
    fprintf(fp,"\n the STDEV of phase C is %.2lf", STDEVC);




}



void csv_close(Waveform *data) {
    if (data != NULL) {
        free(data);
    }
}