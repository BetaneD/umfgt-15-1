//
// Created by Fatima Daudi on 25/04/2026.
//

#include "waveform(2).h"

#include <stdbool.h>
#include <math.h>

#include "io.h"



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

int tolerance_check(int rows, int voltage, int tolerance, double rms) {

    int vmax = voltage + (voltage/tolerance);
    int vmin = voltage - (voltage/tolerance);

    bool in_tolerance = vmin <= rms && rms <= vmax;

    return in_tolerance;
}

double STDEV_A(int rows,Waveform *data) {

    double mean = 0.0;
    double stdev = 0.0;

    for (int j = 0; j < rows; j++) {
        mean += data[j].phase_A;
    }

    if (rows > 0) mean = mean /rows;

    for (int j = 0; j < rows; j++) {
        const double distance = data[j].phase_A - mean;
        stdev += distance * distance;
    }
    stdev = sqrt(stdev/rows);

    return stdev;
}
double STDEV_B(int rows,Waveform *data) {

    double mean = 0.0;
    double stdev = 0.0;

    for (int j = 0; j < rows; j++) {
        mean += data[j].phase_B;
    }

    if (rows > 0) mean = mean /rows;

    for (int j = 0; j < rows; j++) {
        const double distance = data[j].phase_B - mean;
        stdev += distance * distance;
    }
    stdev = sqrt(stdev/rows);

   return stdev;
}
double STDEV_C(int rows,Waveform *data) {

    double mean = 0.0;
    double stdev = 0.0;

    for (int j = 0; j < rows; j++) {
        mean += data[j].phase_C;
    }

    if (rows > 0) mean = mean /rows;

    for (int j = 0; j < rows; j++) {
        const double distance = data[j].phase_C - mean;
        stdev += distance * distance;
    }

    stdev = sqrt(stdev/rows);

   return stdev;
}

double variance_A(int rows,Waveform *data) {
    double mean = 0.0;
    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        mean += data[j].phase_A;
    }

    if (rows > 0) mean = mean /rows;

    for (int j = 0; j < rows; j++) {
        const double distance = data[j].phase_A - mean;
        variance += distance * distance;
    }
    variance = variance/rows;

    return variance;
}
double variance_B(int rows,Waveform *data) {
    double mean = 0.0;
    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        mean += data[j].phase_B;
    }

    if (rows > 0) mean = mean /rows;

    for (int j = 0; j < rows; j++) {
        const double distance = data[j].phase_B - mean;
        variance += distance * distance;
    }
    variance = variance/rows;

    return variance;
}
double variance_C(int rows,Waveform *data) {
    double mean = 0.0;
    double variance = 0.0;

    for (int j = 0; j < rows; j++) {
        mean += data[j].phase_C;
    }

    if (rows > 0) mean = mean /rows;

    for (int j = 0; j < rows; j++) {
        const double distance = data[j].phase_C - mean;
        variance += distance * distance;
    }
    variance = variance/rows;

    return variance;
}
