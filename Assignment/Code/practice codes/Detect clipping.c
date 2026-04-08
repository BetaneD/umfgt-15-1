#include <stdio.h>

int main(){

    int voltage[5] = {1000,2,200,400,300};
    double limit = 324.9;

    for (int i = 0 ; i <= 4 ; i++){

        (voltage[i] >= limit )? printf("sample at %d has surpassed the voltage limit\n",i):printf("");

    }
    return 0;
}