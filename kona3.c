#include <inttypes.h>
#include <math.h>
#include <stdio.h>

float light(uint16_t reg);

float light(uint16_t reg) {
    uint16_t e30 = reg >> 12; 
    uint16_t number = reg;
    for(uint16_t i = 12;i<16;i++){
        number &= ~(1 << i);
    }
    uint16_t r110 = number;
    float lux = 0.01 * pow(2, e30) * (float)r110;
    return (float)lux;
}

int main() {
    uint16_t reg_value = 0b0110110000110101;
    float light_value = light(reg_value);
    printf("Light: %.0f\n", light_value);
    return 0;
}
