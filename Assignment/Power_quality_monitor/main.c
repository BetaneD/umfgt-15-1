 // C program to Create a file
#include "waveform.h"
#include "io.h"

 // Driver code
int main(int argc, char * argv[])
{
 //../power_quality_log.csv

    int rows = 0;
    Waveform *data = csv_open(&rows, argv[1]);

    FILE *fp = fopen("../power_quality_report.txt", "w"); // opens txt file to write report

    print_data_A(rows, data, fp); // prints phase A results
    print_data_B(rows, data, fp); // prints phase B results
    print_data_C(rows, data, fp); // prints phase c results
    print_signal_analysis(rows, data, fp); // prints signal analysis results
    print_sort(rows,data,fp); // prints phases sorted by magnitude results
    fclose(fp);

  csv_close(data);

    return 0;
}