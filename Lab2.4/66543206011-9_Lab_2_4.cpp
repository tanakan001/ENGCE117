#include <stdio.h>
#include <string.h>

char (*explode(char str1[], char splitter))[50];

int main()
{
    char str1[50] = "I/Love/you";
    char splitter = '/';
    char(*out)[50];
    out = explode(str1, splitter);

    for (int i = 0; out[i][0] != '\0'; i++)
    {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }

    return 0;
}

char (*explode(char str1[], char splitter))[50]
{
    int length = strlen(str1), str2_index = 0;
    char (*str2)[50] = new char[50][50]; 

    int count_index = 0;

    for (int i = 0; i < length; i++)
    {
        if (str1[i] == splitter)
        {
            str2[count_index][str2_index] = '\0';
            count_index++;
            str2_index = 0;
        }
        else
        {
            str2[count_index][str2_index] = str1[i];
            str2_index++;
        }
    }

    str2[count_index][str2_index] = '\0';

    return str2;
}
