 // C program to Create a file
#include <stdio.h>
#include "waveform.h"
#include "io.h"

 // Driver code
int main(void)
{

    int rows = 0;
    Waveform *data = csv_open(&rows);

    FILE *fp = fopen("power_quality_report.txt", "w");

    print_data_A(rows, data, fp);
    printf("Entering Phase B\n");
    print_data_B(rows, data, fp);
    printf("Entering Phase C\n");
    print_data_C(rows, data, fp);
   // insertionSort(rows,data);
    fclose(fp);

  csv_close(data);

    return 0;
}