 // C program to Create a file
#include "waveform.h"
#include "io.h"

 // Driver code
int main(int argc, char * argv[])
{
 //power_quality_log.csv

    int rows = 0;
    Waveform *data = csv_open(&rows, argv[1]);

    FILE *fp = fopen("../power_quality_report.txt", "w");

    print_data_A(rows, data, fp);
    printf("Entering Phase B\n");
    print_data_B(rows, data, fp);
    printf("Entering Phase C\n");
    print_data_C(rows, data, fp);
    print_sort(rows,data,fp);
    fclose(fp);

  csv_close(data);

    return 0;
}