#include "io.h"
#include "waveform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Waveform* csv_open(int *rows, const char *filename) {
    int i = 0;

    FILE *fptr = fopen(filename, "r"); // creates a file pointer that opens the file name and reads it

    if (fptr==NULL) {
        printf("ERROR OPENING FILE: check csv file\n"); // checks for error
        exit(1);
    }

    char line[256]; // creates array to hold all data in each line

    fgets(line,sizeof(line), fptr); // skips first line of the csv file

    while (fgets(line, sizeof(line), fptr) != NULL) {
        (*rows)++; // counts how many lines there are
    }

    Waveform *data = malloc((*rows) * sizeof(Waveform));
    //creates a malloc enough space for rows counted and the size of the struct

    if (data == NULL) {
        printf("ERROR ALLOCATING MEMORY: Check malloc\n");// checks for error
        fclose(fptr);
        exit (1);
    }

    rewind(fptr); // goes to the top of the csv file
    fgets(line, sizeof(line), fptr); // skips first line of the csv file

    while(fgets(line, sizeof(line), fptr) != NULL) { // until the last row of the csv file

        char *token;

        token = strtok(line,","); // token points to anything before ,
        if (token) data[i].timestamp = atof(token); // converts the string to a double and stores it in struct

        token = strtok(NULL,",");
        if (token) data[i].phase_A = atof(token);

        token = strtok(NULL,",");
        if (token) data[i].phase_B = atof(token);

        token = strtok(NULL,",");
        if (token) data[i].phase_C = atof(token);

        token = strtok(NULL,",");
        if (token) data[i].line_C = atof(token);

        token = strtok(NULL,",");
        if (token) data[i].frequency = atof(token);

        token = strtok(NULL,",");
        if (token) data[i].power_f = atof(token);

        token = strtok(NULL,",");
        if (token) data[i].thd = atof(token);

        i++; // go to next array element
    }

    fclose(fptr); // closed csv file

    return data; // points to the waveform struct
}

void print_data_A(int rows, Waveform *data, FILE *fp) {

  if (fp == NULL) {
    printf("ERROR OPENING FILE: check csv file\n"); // checks for error
    exit(1);
  }

  ///// PHASE A /////
  fprintf(fp,"\t---PHASE A---");

  double phase_A_rms = rms_A(rows, data); // calling a function
    fprintf(fp,"\n\n the RMS of phase A is %.2lf", phase_A_rms);

  bool toleranceA = tolerance_check(230,10,phase_A_rms); // calling a function
    if (toleranceA) {
        fprintf(fp,"\n In tolerance : YES"); // if bool true print yes
    } else {
        fprintf(fp,"\n In tolerance : NO"); // if bool false print no
    }

  double amplitudeA = amplitude_A(rows,data); // calling a function
    fprintf(fp,"\n the amplitude of phase A is %.2lf", amplitudeA);

  double DC_offsetA = DC_offset_A(rows,data); // calling a function
    fprintf(fp,"\n the DC offset of phase A is %.2lf", DC_offsetA);

  int count = 0;
  double* clippingA = Detect_clipping_A(324.9, rows, data, &count); // calling a function

    if (count == 0) {
        fprintf(fp, "\n clipping not detected");
    } else {
        fprintf(fp, "\n\n clipping detected at timestamp :\n");
        for (int i = 0; i < count; i++) {
            fprintf(fp, "\n %lf", clippingA[i]);
        }
    }

    double VarianceA = variance_A(rows,data); // calling a function
      fprintf(fp,"\n\n the variance of phase A is %.2lf", VarianceA);

    double STDEVA = STDEV_A(rows,VarianceA); // calling a function
      fprintf(fp,"\n the Standard deviation of phase A is %.2lf", STDEVA);

    free(clippingA);

}

void print_data_B(int rows, Waveform *data, FILE *fp) {

  if (fp == NULL) {
    printf("ERROR OPENING FILE: check csv file\n"); // checks for error
    exit(1);
  }

  ///// PHASE B /////
  fprintf(fp,"\n\n\t---PHASE B---");

  double phase_B_rms = rms_B(rows, data); // calling a function
    fprintf(fp,"\n\n the RMS of phase B is %.2lf", phase_B_rms);

  bool toleranceB = tolerance_check(230,10,phase_B_rms);
    if (toleranceB) {
        fprintf(fp,"\n In tolerance : YES");
    } else {
        fprintf(fp,"\n In tolerance : NO");
    }

  double amplitudeB = amplitude_B(rows,data); // calling a function
    fprintf(fp,"\n the amplitude of phase B is %.2lf", amplitudeB);

  double DC_offsetB = DC_offset_B(rows,data); // calling a function
    fprintf(fp,"\n the DC offset of phase B is %.2lf", DC_offsetB);

  int count = 0;
  double* clippingB = Detect_clipping_B(324.9, rows, data, &count); // calling a function

    if (count == 0) {
        fprintf(fp, "\n clipping not detected");
    } else {
        fprintf(fp, "\n\n clipping detected at timestamp :\n");
        for (int i = 0; i < count; i++) {
            fprintf(fp, "\n %lf", clippingB[i]);
        }
    }

  double VarianceB = variance_B(rows,data); // calling a function
    fprintf(fp,"\n\n the variance of phase B is %.2lf", VarianceB);

  double STDEVB = STDEV_B(rows,VarianceB); // calling a function
    fprintf(fp,"\n the Standard deviation of phase B is %.2lf", STDEVB);

    free(clippingB);// clears memory used by a malloc
}

void print_data_C(int rows, Waveform *data, FILE *fp) {

    if (fp == NULL) {
        printf("ERROR OPENING FILE: check csv file\n");
        exit(1);
    }

  ///// PHASE C /////
  fprintf(fp,"\n\n\t---PHASE C---");

  double phase_C_rms = rms_C(rows, data); // calling a function
    fprintf(fp,"\n\n the RMS of phase B is %.2lf", phase_C_rms);

  bool toleranceC = tolerance_check(230,10,phase_C_rms); // calling a function
    if (toleranceC) {
        fprintf(fp,"\n In tolerance : YES");
    } else {
        fprintf(fp,"\n In tolerance : NO");
    }

  double amplitudeC = amplitude_C(rows,data); // calling a function
    fprintf(fp,"\n the amplitude of phase B is %.2lf", amplitudeC);

  double DC_offsetC = DC_offset_C(rows,data); // calling a function
    fprintf(fp,"\n the DC offset of phase C is %.2lf", DC_offsetC);

    int count = 0;
    double* clippingC = Detect_clipping_C(324.9, rows, data, &count); // calling a function

    if (count == 0) {
        fprintf(fp, "\n clipping not detected");
    } else {
        fprintf(fp, "\n\n clipping detected at timestamp :\n");
        for (int i = 0; i < count; i++) {
            fprintf(fp, "\n %lf", clippingC[i]);
        }
    }

  double VarianceC = variance_C(rows,data);  // calling a function
    fprintf(fp,"\n\n the variance of phase C is %.2lf", VarianceC);

  double STDEVC = STDEV_C(rows,VarianceC);  // calling a function
    fprintf(fp,"\n the Standard deviation of phase C is %.2lf", STDEVC);

    free(clippingC);

}

void print_signal_analysis(int rows, Waveform *data, FILE *fp) {

    fprintf(fp,"\n\n\t--- Signal Analysis---");

    double Time = Time_G(rows,data);  // calling a function
    double* Frequency = Frequency_G(rows,data);
    double* PF = PF_G(rows,data);
    double* THD = THD_G(rows,data);

    fprintf(fp,"\n\n over %0.4lf ms window",Time);
    fprintf(fp,"\n\n Frequency range: %0.4lf Hz to %0.4lf Hz",Frequency[0],Frequency[1]);
    fprintf(fp,"\n Power Factor range: %0.4lf to %0.4lf",PF[0],PF[1]);
    fprintf(fp,"\n THD : %0.4lf  %% to %0.4lf %%",THD[0],THD[1]);

    free(Frequency);// clears memory used by a malloc
    free(PF);
    free(THD);


}


void print_sort(int rows, Waveform *data, FILE *fp) {
    if (fp == NULL) {
        printf("ERROR OPENING FILE: check csv file\n");
        exit(1);
    }

    ///// PHASE C /////
    fprintf(fp,"\n\n\t---Value sorted by magnitude---\n");

    double* sortA = insertionSort_A(rows,data); // calling a function
    double* sortB = insertionSort_A(rows,data);
    double* sortC = insertionSort_A(rows,data);

    for (int i = 0; i < rows; i++)
    {
        fprintf(fp,"\n phase_A: %.2lf | phase_B: %.2lf | phase_C: %.2lf",
        sortA[i],
        sortB[i],
        sortC[i]
        );

    }
    printf("\n");
    free(sortA); // clears memory used by a malloc
    free(sortB);
    free(sortC);

}

void csv_close(Waveform *data) {
    if (data != NULL) {
        free(data);
    }
}