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
}
void tolerance_check(int rows, int voltage, int tolerance, double rms) {

    int vmax = voltage + (voltage/tolerance);
    int vmin = voltage - (voltage/tolerance);

    if (vmin <= rms && rms <= vmax){
        printf("\n\n the rms has met 230V nominal");
        } else {

            printf("\n\n the rms has not met 230V nominal");

        }
}

void amplitude_A (int rows,Waveform *data) {

    double max = 0.0;
    double min = 0.0;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].phase_A)? max: data[j].phase_A;
        min = (min <= data[j].phase_A)? min : data[j].phase_A;
    }
    printf("\n\n the peak-to-peak amplitude is %.2f", max - min);
}

void amplitude_B (int rows,Waveform *data) {

    double max = 0.0;
    double min = 0.0;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].phase_B)? max: data[j].phase_B;
        min = (min <= data[j].phase_B)? min : data[j].phase_B;
    }
    printf("\n\n the peak-to-peak amplitude is %.2f", max - min);
}

void amplitude_C (int rows,Waveform *data) {

    double max = 0.0;
    double min = 0.0;

    for (int j = 0; j < rows; j++) {
        max = (max >= data[j].phase_C)? max: data[j].phase_C;
        min = (min <= data[j].phase_C)? min : data[j].phase_C;
    }
    printf("\n\n the peak-to-peak amplitude is %.2f", max - min);
}

void Detect_clipping_A(double limit,int rows,Waveform *data) {
    int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (data[j].phase_A >= limit ) detect++;
    }
    if (detect == 0) {
        printf("\n\n No clipping detected");
    } else {
        printf("\n\n clipping detected at Timestamp :");
        for (int j = 0; j < rows; j++) {
            (data[j].phase_A >= limit )? printf("\n \t %f",data[j].timestamp):printf("");
        }
    }
}

void Detect_clipping_B(double limit,int rows,Waveform *data) {
int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (data[j].phase_B >= limit ) detect++;
    }
    if (detect == 0) {
        printf("\n\n No clipping detected");
    } else {
        printf("\n\n clipping detected at Timestamp:");
        for (int j = 0; j < rows; j++) {
            (data[j].phase_B >= limit )? printf("\n \t %f",data[j].timestamp):printf("");
        }
    }
}

void Detect_clipping_C(double limit,int rows,Waveform *data) {
    int detect = 0;

    for (int j = 0; j < rows; j++) {
        if (data[j].phase_C >= limit ) detect++;
    }
    if (detect == 0) {
        printf("\n\n No clipping detected");
    } else {
        printf("\n\n clipping detected at Timestamp :");
        for (int j = 0; j < rows; j++) {
            (data[j].phase_C >= limit )? printf("\n \t %f",data[j].timestamp):printf("");
        }
    }
}

void DC_offset_A(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_A;
    }
    offset = offset/rows;
    printf("\n\n The DC offset is :%lf",offset);
}

void DC_offset_B(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_B;
    }
    offset = offset/rows;
    printf("\n\n The DC offset is :%lf",offset);
}

void DC_offset_C(int rows,Waveform *data) {

    double offset = 0.0;

    for (int j = 0; j < rows; j++) {
        offset += data[j].phase_C;
    }
    offset = offset/rows;
    printf("\n\n The DC offset is :%lf",offset);
}

#endif //UMFGT_15_1_WAVEFORM_MATH_H
