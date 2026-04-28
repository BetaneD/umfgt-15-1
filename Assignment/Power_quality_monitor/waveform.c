//
// Created by Fatima Daudi on 25/04/2026.
//

#include "waveform.h"
#include "io.h"

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double rms_A (int rows,Waveform *data) {

    double rms = 0.0;

    for (int j = 0; j < rows; j++) {
        rms += data[j].phase_A * data[j].phase_A;
    }

    return sqrt(rms /rows);
}
double rms_B (int rows,Waveform *data) {

    double rms = 0.0;

    for (int j = 0; j < rows; j++) {
        rms += data[j].phase_B * data[j].phase_B;
    }

    return sqrt(rms /rows);;
}
double rms_C (int rows,Waveform *data) {
    double rms = 0.0;

    for (int j = 0; j < rows; j++) {
        rms += data[j].phase_C * data[j].phase_C;
    }

    return sqrt(rms /rows);
}

double amplitude_A (int rows,Waveform *data) {

    double max = 0.0;
    double min = 0.0;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].phase_A)? max: data[j].phase_A;
        min = (min <= data[j].phase_A)? min : data[j].phase_A;
    }
    return max - min ;
}
double amplitude_B (int rows,Waveform *data) {

    double max = 0.0;
    double min = 0.0;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].phase_B)? max: data[j].phase_B;
        min = (min <= data[j].phase_B)? min : data[j].phase_B;
    }
    return max - min ;
}
double amplitude_C (int rows,Waveform *data) {

    double max = 0.0;
    double min = 0.0;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].phase_C)? max: data[j].phase_C;
        min = (min <= data[j].phase_C)? min : data[j].phase_C;
    }
    return max - min ;
}

double DC_offset_A(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_A;
    }
    offset = offset/rows;
    return offset;
}
double DC_offset_B(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_B;
    }
    offset = offset/rows;
    return offset;
}
double DC_offset_C(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_C;
    }
    offset = offset/rows;
    return offset;
}


double* Detect_clipping_A(double limit, int rows, Waveform *data, int *count) {

    int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (data[j].phase_A >= limit)
            detect++;
    }

    double* array_A = malloc(detect * sizeof(double));

    if (array_A == NULL) {
        printf("ERROR: check Detect clipping A\n");
        exit(1);
    }

    int k = 0;
    for (int j = 0; j < rows; j++) {
        if (data[j].phase_A >= limit) {
            array_A[k++] = data[j].timestamp;
        }
    }

     *count = detect;
    return array_A;
}
double* Detect_clipping_B(double limit, int rows, Waveform *data, int *count) {

    int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (data[j].phase_B >= limit)
            detect++;
    }

    double* array_B = malloc(detect * sizeof(double));

    if (array_B == NULL) {
        printf("ERROR: check Detect clipping B\n");
        exit(1);
    }

    int k = 0;
    for (int j = 0; j < rows; j++) {
        if (data[j].phase_B >= limit) {
            array_B[k++] = data[j].timestamp;
        }
    }

    *count = detect;
    return array_B;
}
double* Detect_clipping_C(double limit, int rows, Waveform *data, int *count) {

    int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (data[j].phase_C >= limit)
            detect++;
    }

    double* array_C = malloc(detect * sizeof(double));

    if (array_C == NULL) {
        printf("ERROR: check Detect clipping C\n");
        exit(1);
    }

    int k = 0;
    for (int j = 0; j < rows; j++) {
        if (data[j].phase_C >= limit) {
            array_C[k++] = data[j].timestamp;
        }
    }

    *count = detect;
    return array_C;
}

int tolerance_check(int rows, int voltage, int tolerance, double rms) {

    int vmax = voltage + (voltage/tolerance);
    int vmin = voltage - (voltage/tolerance);

    bool in_tolerance = vmin <= rms && rms <= vmax;

    return in_tolerance;
}

double mean_A(int rows,Waveform *data) {
    double mean = 0.0;

    for (int j = 0; j < rows; j++) {
    mean += data[j].phase_A;
}

    return mean/rows;
}
double mean_B(int rows,Waveform *data) {

    double mean = 0.0;

    for (int j = 0; j < rows; j++) mean += data[j].phase_B;

    return mean/rows;
}
double mean_C(int rows,Waveform *data) {

    double mean = 0.0;

    for (int j = 0; j < rows; j++) mean += data[j].phase_C;

    return mean/rows;
}

double variance_A(int rows,Waveform *data,double mean) {
    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        double distance = data[j].phase_A - mean;
        variance += distance * distance;
    }
    variance = variance/rows;

    return variance;
}
double variance_B(int rows,Waveform *data,double mean) {
    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        double distance = data[j].phase_B - mean;
        variance += distance * distance;
    }
    variance = variance/rows;

    return variance;
}
double variance_C(int rows,Waveform *data,double mean) {
    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        double distance = data[j].phase_C - mean;
        variance += distance * distance;
    }
    variance = variance/rows;

    return variance;
}

double STDEV_A(int rows,double variance_A) {

    double stdev = 0.0;

    stdev = sqrt(variance_A);

    return stdev;
}
double STDEV_B(int rows,double variance_B) {

    double stdev = 0.0;

    stdev = sqrt(variance_B);

    return stdev;
}
double STDEV_C(int rows,double variance_C) {

    double stdev = 0.0;

    stdev = sqrt(variance_C);

    return stdev;
}
