#include <inttypes.h>
#include <math.h>
#include <stdio.h>

float humidity(uint16_t reg);

float humidity(uint16_t reg) {
    double humidity = (double)reg / pow(2, 16) * 100;
    return (float)humidity;
}

int main() {
    uint16_t reg_value = 0x8000;
    float humidity_percentage = humidity(reg_value);
    printf("Humidity: %.0f\n", humidity_percentage);
    return 0;
}
