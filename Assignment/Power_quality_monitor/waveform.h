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

int Detect_clipping_A(double limit,int rows,Waveform *data);
int Detect_clipping_B(double limit,int rows,Waveform *data);
int Detect_clipping_C(double limit,int rows,Waveform *data);

int tolerance_check(int rows, int voltage, int tolerance, double rms);

double STDEV_A(int rows,Waveform *data);
double STDEV_B(int rows,Waveform *data);
double STDEV_C(int rows,Waveform *data);

double variance_A(int rows,Waveform *data);
double variance_B(int rows,Waveform *data);
double variance_C(int rows,Waveform *data);

double get_A(Waveform w);
double get_B(Waveform w);
double get_C(Waveform w);
/* sorting function */
/*typedef double (*ValueFunc)(Waveform);
void insertionSort(int rows, Waveform *data, ValueFunc getValue);
*/
void csv_close(Waveform *data);

#endif //UMFGT_15_1_WAVEFORM_H
