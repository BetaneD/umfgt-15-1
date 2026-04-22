//
// Created by Fatima Daudi on 22/04/2026.
//

#ifndef UMFGT_15_1_WAVEFORM_MATH_H
#define UMFGT_15_1_WAVEFORM_MATH_H

double rms_A (int rows,Waveform *data) {

    double rms = 0.0;

    for (int j = 0; j < rows; j++) {
        rms += data[j].phase_A * data[j].phase_A;
    }

    if (rows > 0) {
        rms = sqrt(rms /rows);
    }
    return rms;
}

double rms_B (int rows,Waveform *data) {

    double rms = 0.0;

    for (int j = 0; j < rows; j++) {
        rms += data[j].phase_B * data[j].phase_B;
    }

    if (rows > 0) {
        rms = sqrt(rms /rows);
    }
    return rms;
}
double rms_C (int rows,Waveform *data) {

    double rms = 0.0;

    for (int j = 0; j < rows; j++) {
        rms += data[j].phase_C * data[j].phase_C;
    }

    if (rows > 0) {
        rms = sqrt(rms /rows);
    }
    return rms;

void tolerance_check(int rows, int voltage, int tolerance, double rms) {

    int vmax = voltage + (voltage/tolerance);
    int vmin = voltage - (voltage/tolerance);

    if (vmin <= rms && rms <= vmax){
        printf("\n\n the rms has met 230V nominal");
        } else {

            printf("\n\n the rms has not met 230V nominal");

        }
}

#endif //UMFGT_15_1_WAVEFORM_MATH_H
