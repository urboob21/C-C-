#include <stdint.h>
#include <stdio.h>

#define SCLK 100000000
int main()
{
    float value = 32*(1/((float)SCLK))*1000000;
        printf("%f\n", value);

    return 0;
}