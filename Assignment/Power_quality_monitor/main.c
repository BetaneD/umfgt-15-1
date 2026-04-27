 // C program to Create a file
#include <stdio.h>
#include "waveform.h"
#include "io.h"

 // Driver code
int main(void)
{

    int rows = 0;
    Waveform *data = csv_open(&rows);

    FILE *fp = fopen("../power_quality_report.txt", "w");

    print_data_A(rows, data, fp);
    printf("Entering Phase B\n");
    print_data_B(rows, data, fp);
    printf("Entering Phase C\n");
    print_data_C(rows, data, fp);
    fclose(fp);


    printf("\n\n printing values for comaparison");
        int detect = 0;

        for (int j = 0; j < rows; j++) {
            if (data[j].phase_A >= 324.9 ) detect++;
        }
        if (detect == 0) {
            printf("\n\n No clipping detected");
        } else {
            printf("\n\n clipping detected at Timestamp :");
            for (int j = 0; j < rows; j++) {
                (data[j].phase_A >= 324.9)? printf("\n \t %f",data[j].timestamp):printf("");
            }
        }


  csv_close(data);

    return 0;
}