#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

void shuffle(uint8_t *list, uint16_t list_size);

int find_elem( int value, uint8_t a[], int n );

int find_elem( int value, uint8_t a[], int n )
{
    int i = 0;

    while ( i < n && a[i] != value ) i++;

    return i == n ? -1 : i;
}

void shuffle(uint8_t *list, uint16_t list_size)
{
    uint8_t *random_list;
    uint8_t roll;
    uint8_t *prev_rolls;
    srand(time(NULL));
    for(uint8_t i=0; i < list_size; i++)
    {
        while(find_elem(roll = rand() % (list_size - i), prev_rolls, i))
        {            
        }
        *(random_list + i) = list[roll];
        *(prev_rolls++) = roll;
    }
    for(uint8_t i = 0; i < list_size; i++)
    {
        list[i] = random_list[i];
    }
}

int main()
{
    uint8_t list[8] = {1,2,3,4,5,6,7,8};
    shuffle(list, 8);
    for (int i=0;i < (sizeof (list) /sizeof (list[0]));i++) 
    {
        printf("%u\n",list[i]);
    }
}

