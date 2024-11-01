#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

uint8_t hexago(uint32_t luku);

uint8_t hexago(uint32_t luku)
{
    float val = 8 * luku + 1;
 
    float x = 1 + sqrt(val);
 
    // Calculate the value for n
    float n = (x) / 4;
 
    // Check if n - floor(n)
    // is equal to 0
    if ((n - (int)n) == 0)
        return 1;
 
    else
        return 0;
}

int main()
{
    int N = 14;
 
    if (hexago(N) == true)
        printf("Yes");
 
    else
        printf("No");
    return 0;
}