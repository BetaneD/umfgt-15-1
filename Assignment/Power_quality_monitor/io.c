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

  int clippingA= Detect_clipping_A(324.9,rows,data);
    if (clippingA <= 0) {
        fprintf(fp,"\n clipping not detected");
    } else {
        fprintf(fp,"\n clipping detected at %d ", clippingA);
        fprintf(fp,"timestamps");
    }

  double DC_offsetA = DC_offset_A(rows,data);
  fprintf(fp,"\n the DC offset of phase A is %.2lf", DC_offsetA);

  double STDEVA = STDEV_A(rows,data);
  fprintf(fp,"\n the STDEV of phase A is %.2lf", STDEVA);

  double VarianceA = variance_A(rows,data);
  fprintf(fp,"\n the variance of phase A is %.2lf", VarianceA);

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

  int clippingB= Detect_clipping_B(324.9,rows,data);
    if (clippingB <= 0) {
        fprintf(fp,"\n clipping not detected");
    } else {
        fprintf(fp,"\n clipping detected at %d ", clippingB);
        fprintf(fp,"timestamps");
    }

  double DC_offsetB = DC_offset_B(rows,data);
  fprintf(fp,"\n the DC offset of phase B is %.2lf", DC_offsetB);

  double STDEVB = STDEV_B(rows,data);
  fprintf(fp,"\n the STDEV of phase B is %.2lf", STDEVB);

  double VarianceB = variance_B(rows,data);
  fprintf(fp,"\n the variance of phase B is %.2lf", VarianceB);

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

  int clippingC= Detect_clipping_C(324.9,rows,data);
    if (clippingC <= 0) {
        fprintf(fp,"\n clipping not detected");
    } else {
        fprintf(fp,"\n clipping detected at %d ", clippingC);
        fprintf(fp,"timestamps");
    }

  double DC_offsetC = DC_offset_C(rows,data);
    fprintf(fp,"\n the DC offset of phase C is %.2lf", DC_offsetC);

  double STDEVC = STDEV_C(rows,data);
    fprintf(fp,"\n the STDEV of phase C is %.2lf", STDEVC);

  double VarianceC = variance_C(rows,data);
    fprintf(fp,"\n the variance of phase C is %.2lf", VarianceC);

}


void csv_close(Waveform *data) {
    if (data != NULL) {
        free(data);
    }
}