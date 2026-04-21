#include <stdio.h>

int main()
{
    int rms[3] = {10,230,9};
    int voltage = 230;
    int tolerance = 10;
    
    int vmax = voltage + (voltage/tolerance);
    int vmin = voltage - (voltage/tolerance);
    
    for (int i = 0 ; i <= 2 ; i++){
        
        if (vmin <= rms[i] && rms[i]<= vmax){
            continue;
        } else { 
            
            printf("position %d is out of tolerance\n" ,i );
            
        }
        
    }
    

    return 0;
}