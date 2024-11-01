#include <inttypes.h>
#include <math.h>
#include <stdio.h>



uint32_t pressure(uint8_t xlsb, uint8_t lsb, uint8_t msb);

uint32_t pressure(uint8_t xlsb, uint8_t lsb, uint8_t msb)
{
    uint32_t number = (uint32_t)msb << 12 | (uint32_t)lsb << 4 | (uint32_t)xlsb >> 4;
    return number;
}




int main() 
{
    uint8_t xlsb =-34;
    uint8_t lsb = -68;
    uint8_t msb = 24;
    uint32_t pressure_value = pressure(xlsb, lsb, msb);
    printf("Pressure: %u\n", pressure_value);
    return 0;
}