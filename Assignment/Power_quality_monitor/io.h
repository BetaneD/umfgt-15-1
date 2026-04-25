//
// Created by Fatima Daudi on 25/04/2026.
//

#ifndef UMFGT_15_1_IO_H
#define UMFGT_15_1_IO_H
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

Waveform* csv_open(int *rows);

#endif //UMFGT_15_1_IO_H
