#include <stdio.h>
#include <inttypes.h>
#include <string.h>

float mean(char *list);

int stringToInt(const char *str);

int stringToInt(const char *str) {
    if (str == NULL) {
        return 0; // Indicate failure if input string is NULL
    }

    int num = 0;
    int sign = 1;
    int i = 0;

    // Check for an empty string
    if (str[0] == '\0') {
        return 0; // Indicate failure for empty string
    }

    // Handle optional sign
    if (str[0] == '-') {
        sign = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }

    // Convert characters to integer
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0; // Indicate failure for non-digit characters
        }
        num = num * 10 + (str[i] - '0');

        // Check for overflow
    }

    return num * sign;
}

float mean(char *list)
{
    
    char *tokens;
    int sum = 0;
    int i = 0;
    char delimiters[] = {','};
    tokens = strtok(list, delimiters);
    sum += stringToInt(tokens);
    while (tokens != NULL) {
        tokens = strtok(NULL, delimiters);
        sum += stringToInt(tokens);
        i++;
    }
    return (float)sum/(float)i;
}

int main()
{
    char numbers[] = "201,53,12,31,5";
    printf("%.01f",mean(numbers));
    return 0;
}