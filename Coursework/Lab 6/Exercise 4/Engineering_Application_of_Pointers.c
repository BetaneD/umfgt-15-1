/******************************************************************************

Your Task:

     ◦ Write a function which takes as parameters the values of resistance,
       capacitance, inductance,and angular frequency
       (ω and pointers to variables that will store the calculated impedance
       and phase angle. Use the sqrt() and acos()
       functions from the <math.h> library.


*******************************************************************************/
#include <stdio.h>
#include <math.h>



void calculate_rlc_properties(double R, double L, double C, double omega, double *impedance,double *phase_angle){

    double Z_calc = sqrt(R*R + pow((omega*L - 1/(omega*C)), 2));

    double phi_calc = acos(R / Z_calc);

    *impedance = Z_calc; // Store the result in the main function's variable

    *phase_angle = phi_calc; // Store the result in the main function's variable

}

int main(){

    double Rv = 100.0;
    double Lv = 0.1;
    double Cv = 0.001;
    double Ov = 377.0;

    double imp,phase;

    calculate_rlc_properties(Rv,Lv , Cv, Ov, &imp, &phase);

    printf("Input Values:\n");
    printf("Resistance: %.4lf Ohms\n", Rv);
    printf("Capacitance: %.4lf F\n", Cv);
    printf("Inductance: %.4lf H\n", Lv);
    printf("Angular Frequency: %.4lf rad/s\n\n", Ov);

    printf("Your Impedance is: %.4lf Ohms\n", imp);
    printf("Your Phase Angle is : %.4lf radians\n", phase);

    return 0;
}