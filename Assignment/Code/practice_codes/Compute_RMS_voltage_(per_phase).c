#include <stdio.h>
#include <math.h>

int main()
{
    int rms;
    int a[3] = {6,9,3};
    int x = 0;
    int count = 0;

    for (int i = 0; i < 3 ; i++ ){

        a[i] *= a[i];
        x += a[i];
        printf("x = %d ", x);
        count++;
    }

    rms = sqrt(x/count);

    printf("\n\tthe rms is %d", rms);

    return 0;
}
