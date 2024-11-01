#include <math.h>
#include <stdio.h>
#include <inttypes.h>

int64_t factorial(int8_t n);

int64_t factorial(int8_t n)
{
    if(n > 20)
    {
        return -1;
    }
    int64_t result = 1;
    for(uint8_t i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    int8_t number;
    printf("Enter an integer: ");
    scanf("%hhd", &number);
    printf("Factorial: %ld\n", factorial(number));
    return 0;
}