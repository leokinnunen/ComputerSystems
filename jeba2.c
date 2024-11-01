#include <stdio.h>
#include <inttypes.h>



void movavg(float *array, uint8_t array_size, uint8_t window_size);

void movavg(float *array, uint8_t array_size, uint8_t window_size)
{
    float average;
    for (int j = 0; j <= array_size-window_size; j++)
    {
        float sum = 0;
        for(int i = 0; i < window_size; i++)
        {
            sum += (array[i+j]);
        }
        average = sum/(float)window_size;
        printf("%.2f,", average);
    }
    
}


int main()
{
    float data[5] = { 1.0, 2.0, 4.0, 6.0, 9.0 };
    movavg(data, 5, 3);
}