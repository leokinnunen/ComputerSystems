#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void charcounter(char *str, uint8_t *result);

void charcounter(char *str, uint8_t *result)
{
    char vowels[]= {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    uint8_t vowel_count = 0;
    uint8_t consonant_count = 0;
    int j;
    for (int i = 0; str[i] != '\0'; i++)
    {
        //Tarkistaa, että kyseessä on normaali kirjain  
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            {
                for (j = 0; j < 11; j++)
                {
                    if(str[i]==vowels[j])
                    {
                        vowel_count++;
                        break;
                    }                    
                }
                
                if(j==11)
                {
                    consonant_count++;
                }
            }
        
    }
    result[0] = vowel_count;
    result[1] = consonant_count;
}

int main()
{
    
}
