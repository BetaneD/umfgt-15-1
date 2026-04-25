 // C program to Create a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "waveform(2).h"
#include "../../Assignment practice/Code/practice_codes/csv_read/sort(2).h"
#include "io.h"

 // Driver code
int main(void)
{

  int rows = 0;
  Waveform *data = csv_open(&rows);
  ///// PHASE A /////
  printf("\n\n---PHASE A---");

  double phase_A_rms = rms_A(rows, data);
  printf("\n the RMS of phase A is %.2f", phase_A_rms);
  tolerance_check(rows,230,10,phase_A_rms);
  amplitude_A(rows,data);
  Detect_clipping_A(324.9,rows,data);
  DC_offset_A(rows,data);
  STDEV_A(rows,data);

  ///// PHASE B /////
  printf("\n\n---PHASE B---");
  double phase_B_rms = rms_B(rows, data);
  printf("\n the RMS of phase B is %.2f", phase_B_rms);
  tolerance_check(rows,230,10,phase_B_rms);
  amplitude_B(rows,data);
  Detect_clipping_B(324.9,rows,data);
  DC_offset_B(rows,data);
  STDEV_B(rows,data);

  ///// PHASE C /////
  printf("\n\n---PHASE C---");
  double phase_C_rms = rms_C(rows, data);
  printf("\n the RMS of phase C is %.2f", phase_C_rms);
  tolerance_check(rows,230,10,phase_C_rms);
  amplitude_C(rows,data);
  Detect_clipping_C(324.9,rows,data);
  DC_offset_C(rows,data);
  STDEV_C(rows,data);


  void csv_close();

    return 0;
}