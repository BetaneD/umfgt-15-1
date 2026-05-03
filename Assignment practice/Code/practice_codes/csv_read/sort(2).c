//
// Created by Fatima Daudi on 25/04/2026.
//

#include "sort(2).h"
#include "io.h"

void insertionSort(const int rows,Waveform *data) {

    for (int i = 1; i < rows; i++)
    {
        double key = data[i].phase_A ;
        int j = i - 1;

        while (j >= 0 && data[j].phase_A  > key)
        {
            data[j+1].phase_A = data[j].phase_A;
            j = j - 1;
        }

        data[j+1].phase_A = key;
    }

    for (int i = 0; i < rows; i++)
    {
        printf("\n%f ", data[i].phase_A);
    }
}