#ifndef UMFGT_15_1_IO_H
#define UMFGT_15_1_IO_H

#include <stdio.h>

typedef struct {

    float timestamp;
    float phase_A;
    float phase_B;
    float phase_C;
    float line_C;
    float frequency;
    float power_f;
    float thd;
}Waveform;

Waveform* csv_open(int *rows, const char *filename);
void print_data_A(int rows, Waveform *data, FILE *fp);
void print_data_B(int rows, Waveform *data, FILE *fp);
void print_data_C(int rows, Waveform *data, FILE *fp);
void print_sort(int rows, Waveform *data, FILE *fp);
void print_General(int rows, Waveform *data, FILE *fp);



#endif //UMFGT_15_1_IO_H
