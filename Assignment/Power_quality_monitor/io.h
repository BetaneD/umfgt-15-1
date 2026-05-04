#ifndef UMFGT_15_1_IO_H
#define UMFGT_15_1_IO_H

#include <stdio.h>

typedef struct { // created struct to store data from csv

    double timestamp;
    double phase_A;
    double phase_B;
    double phase_C;
    double line_C;
    double frequency;
    double power_f;
    double thd;
}Waveform;

// function declarations

Waveform* csv_open(int *rows, const char *filename);
void print_data_A(int rows, Waveform *data, FILE *fp);
void print_data_B(int rows, Waveform *data, FILE *fp);
void print_data_C(int rows, Waveform *data, FILE *fp);
void print_sort(int rows, Waveform *data, FILE *fp);
void print_signal_analysis(int rows, Waveform *data, FILE *fp);



#endif //UMFGT_15_1_IO_H
