#include <stdio.h>
#include <inttypes.h>



int8_t tictactoe_check(int8_t * gameboard, int win_len);

int8_t tictactoe_check(int8_t * gameboard, int win_len)
{
    
    uint8_t len1, len2, wins1, wins2;
    wins1 = 0;
    wins2 = 0;

    //Tarkistaa, onko riveillä voitto suoraa:
    for(int i = 0; i < 100; i++)
    {
        if(gameboard[i]==0)
        {
            len1 = 0;
            len2 = 0;
        }
        if(gameboard[i]==1)
        {
            len1++;
            len2 = 0;
        }
        if(gameboard[i]==2)
        {
            len1 = 0;
            len2++;
        }
        if(len1 == win_len)
        {
            wins1++;
            len1 = 0;
        }
        if(len2 == win_len)
        {
            wins2++;
            len2 = 0;
        }
            
    }
    //Tarkistaa, onko sarakkeilla voitto suoraa:
    for(int j = 0;j<10;j++)
    {
        for(int i = 0; i < 10; i++)
        {
            if(gameboard[i*10+j]==0)
            {
                len1 = 0;
                len2 = 0;
            }
            if(gameboard[i*10+j]==1)
            {
                len1++;
                len2 = 0;
            }
            if(gameboard[i*10+j]==2)
            {
                len1 = 0;
                len2++;
            }
            if(len1 == win_len)
            {
                wins1++;
                len1 = 0;
            }
            if(len2 == win_len)
            {
                wins2++;
                len2 = 0;
            }
        }
        len1 = 0;
        len2 = 0;
    }
    //Tarkistaa, onko ov diagonaaleilla ylhäältä keskelle voittosuoraa:
    for(int j = 0;j<10;j++)
    {
        for(int i = 0; i <= j; i++)
        {
            if(gameboard[j+9*i]==0)
            {
                len1 = 0;
                len2 = 0;
            }
            if(gameboard[j+9*i]==1)
            {
                len1++;
                len2 = 0;
            }
            if(gameboard[j+9*i]==2)
            {
                len1 = 0;
                len2++;
            }
            if(len1 == win_len)
            {
                wins1++;
                len1 = 0;
            }
            if(len2 == win_len)
            {
                wins2++;
                len2 = 0;
            }
        }
        len1 = 0;
        len2 = 0;
    }
    //Tarkistaa, onko ov diagonaaleilla keskeltä alhaalle voittosuoraa:
    for(int j = 8;j >=0;j--)
    {
        for(int i = 0; i <= j; i++)
        {
            if(gameboard[j+(9-j)*11+9*i]==0)
            {
                len1 = 0;
                len2 = 0;
            }
            if(gameboard[j+(9-j)*11+9*i]==1)
            {
                len1++;
                len2 = 0;
            }
            if(gameboard[j+(9-j)*11+9*i]==2)
            {
                len1 = 0;
                len2++;
            }
            if(len1 == win_len)
            {
                wins1++;
                len1 = 0;
            }
            if(len2 == win_len)
            {
                wins2++;
                len2 = 0;
            }
        }
        len1 = 0;
        len2 = 0;
    }
    //Tarkistaa, onko vo diagonaaleilla keskeltä ylhäälle voittosuoraa:
    for(int j = 0;j<10;j++)
    {
        for(int i = 0; i < 10-j; i++)
        {
            
            if(gameboard[j+11*i]==0)
            {   
                
                len1 = 0;
                len2 = 0;
            }
            if(gameboard[j+11*i]==1)
            {
                len1++;
                len2 = 0;
            }
            if(gameboard[j+11*i]==2)
            {
                len1 = 0;
                len2++;
            }
            if(len1 == win_len)
            {
                wins1++;
                len1 = 0;
            }
            if(len2 == win_len)
            {
                wins2++;
                len2 = 0;
            }
        }
        len1 = 0;
        len2 = 0;
    }
     //Tarkistaa, onko vo diagonaaleilla keskeltä alhaalle voittosuoraa:
    for(int j = 8;j >=0;j--)
    {
        for(int i = 0; i <= j; i++)
        {
            if(gameboard[(9-j)*10+11*i]==0)
            {
                len1 = 0;
                len2 = 0;
            }
            if(gameboard[(9-j)*10+11*i]==1)
            {
                len1++;
                len2 = 0;
            }
            if(gameboard[(9-j)*10+11*i]==2)
            {
                len1 = 0;
                len2++;
            }
            if(len1 == win_len)
            {
                wins1++;
                len1 = 0;
            }
            if(len2 == win_len)
            {
                wins2++;
                len2 = 0;
            }
        }
        len1 = 0;
        len2 = 0;
    }
    if(wins1&&wins2)
        return 0;
    if(wins1)
        return 1;
    if(wins2)
        return 2;
    if(!(wins1||wins2))
    return 0;

}

int main() {
    int8_t gameboard[100] = {
        0, 1, 2, 1, 1, 1, 0, 0, 0, 0, // Row 1
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0, // Row 2
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0, // Row 3
        0, 2, 1, 0, 2, 2, 0, 0, 0, 0, // Row 4
        0, 1, 0, 0, 0, 2, 0, 0, 0, 0, // Row 5
        0, 1, 1, 2, 1, 1, 2, 1, 0, 0, // Row 6
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // Row 7
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, // Row 8
        0, 2, 0, 0, 0, 0, 0, 0, 0, 0, // Row 9
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0  // Row 10
    };

    printf("%d", tictactoe_check(gameboard, 3));
}