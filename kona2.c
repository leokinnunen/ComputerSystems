#include <inttypes.h>
#include <math.h>
#include <stdio.h>

float temperature(uint16_t reg);

float temperature(uint16_t reg) {
    uint16_t inter = reg >> 2;
    double result = (double)inter * 0.03125;
    return (float)result;
}

int main() {
    uint16_t reg_value = 0b0011001000000000;
    float temperature_value = temperature(reg_value);
    printf("Temperature: %.0f\n", temperature_value);
    return 0;
}
