//
// Created by Fatima Daudi on 23/04/2026.
//

#ifndef UMFGT_15_1_SORT_H
#define UMFGT_15_1_SORT_H

void insertionSort(int rows,Waveform *data) {

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
#endif //UMFGT_15_1_SORT_H
