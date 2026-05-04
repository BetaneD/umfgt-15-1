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

    double max = data[0].phase_A;
    double min = data[0].phase_A;

    for (int j = 0; j < rows; j++) {
        max = (max <= data[j].phase_A)? max: data[j].phase_A;
        min = (min >= data[j].phase_A)? min : data[j].phase_A;
    }
    return max - min ;
}
double amplitude_B (int rows,Waveform *data) {

    double max = data[0].phase_B;
    double min = data[0].phase_B;

    for (int j = 0; j < rows; j++) {
        max = (max <= data[j].phase_B)? max: data[j].phase_B;
        min = (min >= data[j].phase_B)? min : data[j].phase_B;
    }
    return max - min ;
}
double amplitude_C (int rows,Waveform *data) {

    double max = data[0].phase_C;
    double min = data[0].phase_C;

    for (int j = 0; j < rows; j++) {
        max = (max <= data[j].phase_C)? max: data[j].phase_C;
        min = (min >= data[j].phase_C)? min : data[j].phase_C;
    }
    return max - min ;
}

double DC_offset_A(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_A;
    }
    return offset/rows;
}
double DC_offset_B(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_B;
    }
    return offset/rows;
}
double DC_offset_C(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_C;
    }
    return offset/rows;
}


double* Detect_clipping_A(double limit, int rows, Waveform *data, int *count) {

    int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (fabs(data[j].phase_A) >= limit)
            detect++;
    }

    double* array_A = malloc(detect * sizeof(double));

    if (array_A == NULL) {
        printf("ERROR: check Detect clipping A\n");
        exit(1);
    }

    int k = 0;
    for (int j = 0; j < rows; j++) {
        if (fabs(data[j].phase_A) >= limit) {
            array_A[k++] = data[j].timestamp;
        }
    }

    *count = detect;

    if (detect == 0) {
        *count = 0;
        return NULL;
    }

    return array_A;
}
double* Detect_clipping_B(double limit, int rows, Waveform *data, int *count) {

    int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (fabs(data[j].phase_B) >= limit)
            detect++;
    }

    double* array_B = malloc(detect * sizeof(double));

    if (array_B == NULL) {
        printf("ERROR: check Detect clipping B\n");
        exit(1);
    }

    int k = 0;
    for (int j = 0; j < rows; j++) {
        if (fabs(data[j].phase_B) >= limit) {
            array_B[k++] = data[j].timestamp;
        }
    }

    *count = detect;

    if (detect == 0) {
        *count = 0;
        return NULL;
    }

    return array_B;
}
double* Detect_clipping_C(double limit, int rows, Waveform *data, int *count) {

    int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (fabs(data[j].phase_C) >= limit)
            detect++;
    }

    double* array_C = malloc(detect * sizeof(double));

    if (array_C == NULL) {
        printf("ERROR: check Detect clipping C\n");
        exit(1);
    }

    int k = 0;
    for (int j = 0; j < rows; j++) {
        if (fabs(data[j].phase_C) >= limit) {
            array_C[k++] = data[j].timestamp;
        }
    }

    *count = detect;

    if (detect == 0) {
        *count = 0;
        return NULL;
    }

    return array_C;
}

bool tolerance_check(int voltage, int tolerance, double rms) {

    double vmax = voltage + (voltage*tolerance/100);
    double vmin = voltage - (voltage*tolerance/100);

    return vmin <= rms && rms <= vmax;
}

double variance_A(int rows,Waveform *data) {
    double mean = 0.0;

    for (int j = 0; j < rows; j++) mean += data[j].phase_A;
    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        double distance = data[j].phase_A - mean;
        variance += distance * distance;
    }
    return variance/rows;
}
double variance_B(int rows,Waveform *data) {

    double mean = 0.0;

    for (int j = 0; j < rows; j++) mean += data[j].phase_B;

    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        double distance = data[j].phase_B - mean;
        variance += distance * distance;
    }
    return variance/rows;
}
double variance_C(int rows,Waveform *data) {
    double mean = 0.0;

    for (int j = 0; j < rows; j++) mean += data[j].phase_C;

    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        double distance = data[j].phase_C - mean;
        variance += distance * distance;
    }
    return variance/rows;
}

double STDEV_A(int rows,double variance_A) {

    return sqrt(variance_A);
}
double STDEV_B(int rows,double variance_B) {

    return sqrt(variance_B);
}
double STDEV_C(int rows,double variance_C) {

    return sqrt(variance_C);
}

double* insertionSort_A(int rows, Waveform *data){
    double* sort_A = malloc(rows * sizeof(double));

    if (sort_A == NULL) {
        printf("ERROR: check insertionSort A\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        sort_A[i] = data[i].phase_A;
    }

    for (int i = 1; i < rows; i++)
    {
        double key = sort_A[i];

        int j = i - 1;

        while (j >= 0 && fabs(sort_A[j]) > fabs(key))
        {
            sort_A[j + 1] = sort_A[j];
            j = j - 1;
        }

        sort_A[j + 1] = key;
    }
    return sort_A;
}
double* insertionSort_B(int rows, Waveform *data){
    double* sort_B = malloc(rows * sizeof(double));

    if (sort_B == NULL) {
        printf("ERROR: check insertionSort B\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        sort_B[i] = data[i].phase_B;
    }

    for (int i = 1; i < rows; i++)
    {
        double key = sort_B[i];

        int j = i - 1;

        while (j >= 0 && fabs(sort_B[j]) > fabs(key))
        {
            sort_B[j + 1] = sort_B[j];
            j = j - 1;
        }

        sort_B[j + 1] = key;
    }
    return sort_B;
}
double* insertionSort_C(int rows, Waveform *data){
    double* sort_C = malloc(rows * sizeof(double));

    if (sort_C == NULL) {
        printf("ERROR: check insertionSort C\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        sort_C[i] = data[i].phase_C;
    }

    for (int i = 1; i < rows; i++)
    {
        double key = sort_C[i];

        int j = i - 1;

        while (j >= 0 && fabs(sort_C[j]) > fabs(key))
        {
            sort_C[j + 1] = sort_C[j];
            j = j - 1;
        }

        sort_C[j + 1] = key;
    }
    return sort_C;
}

double Time_G (int rows,Waveform *data) {

    double max = data[0].timestamp;

    for (int j = 0; j < rows; j++) {
        if (data[j].timestamp > max) max = data[j].timestamp;
    }

    return max ;
}
double* Frequency_G (int rows,Waveform *data) {

    double* array_FREQ = malloc(2 * sizeof(double));

    if (array_FREQ == NULL) {
        printf("ERROR: check Frequency G \n");
        exit(1);
    }

    double max = data[0].frequency;
    double min = data[0].frequency;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].frequency)? max: data[j].frequency;
        min = (min <= data[j].frequency)? min : data[j].frequency;
    }
    array_FREQ[1] = max;
    array_FREQ[0] = min;

    return array_FREQ;
}

double* PF_G (int rows,Waveform *data) {

    double* array_PF = malloc(2 * sizeof(double));

    if (array_PF == NULL) {
        printf("ERROR: check Power factor G \n");
        exit(1);
    }

    double max = data[0].power_f;
    double min = data[0].power_f;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].power_f)? max: data[j].power_f;
        min = (min <= data[j].power_f)? min : data[j].power_f;
    }
    array_PF[1] = max;
    array_PF[0] = min;

    return array_PF;
}

double* THD_G (int rows,Waveform *data) {

    double* array_THD = malloc(2 * sizeof(double));

    if (array_THD == NULL) {
        printf("ERROR: check THD G \n");
        exit(1);
    }

    double max = data[0].thd;
    double min = data[0].thd;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].thd)? max: data[j].thd;
        min = (min <= data[j].thd)? min : data[j].thd;
    }
    array_THD[1] = max;
    array_THD[0] = min;

    return array_THD;
}