//
// Created by Fatima Daudi on 25/04/2026.
//

#ifndef UMFGT_15_1_WAVEFORM_H
#define UMFGT_15_1_WAVEFORM_H
#include "io.h"


double rms_A (int rows,Waveform *data);
double rms_B (int rows,Waveform *data);
double rms_C (int rows,Waveform *data);

double amplitude_A (int rows,Waveform *data);
double amplitude_B (int rows,Waveform *data);
double amplitude_C (int rows,Waveform *data);

double DC_offset_A(int rows,Waveform *data);
double DC_offset_B(int rows,Waveform *data);
double DC_offset_C(int rows,Waveform *data);

double* Detect_clipping_A(double limit, int rows, Waveform *data, int *count);
double* Detect_clipping_B(double limit, int rows, Waveform *data, int *count);
double* Detect_clipping_C(double limit, int rows, Waveform *data, int *count);

int tolerance_check(int rows, int voltage, int tolerance, double rms);

double mean_A(int rows,Waveform *data);
double mean_B(int rows,Waveform *data);
double mean_C(int rows,Waveform *data);

double variance_A(int rows,Waveform *data,double mean_A);
double variance_B(int rows,Waveform *data,double mean_B);
double variance_C(int rows,Waveform *data,double mean_c);

double STDEV_A(int rows,double variance_A);
double STDEV_B(int rows,double variance_B);
double STDEV_C(int rows,double variance_C);

double* insertionSort_A(int rows, Waveform *data);
double* insertionSort_B(int rows, Waveform *data);
double* insertionSort_C(int rows, Waveform *data);

void csv_close(Waveform *data);

#endif //UMFGT_15_1_WAVEFORM_H
