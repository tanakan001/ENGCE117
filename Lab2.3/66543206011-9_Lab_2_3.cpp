#include <stdio.h>
#include <string.h>

void explode(const char str1[], char splitter, char str2[][10], int *count);

int main()
{
    char out[20][10];
    int num;
    explode("I/Love/You", '/', out, &num);
    return 0;
}

void explode(const char str1[], char splitter, char str2[][10], int *count)
{
    int length = strlen(str1);
    int str2_index = 0;
    *count = 0;

    for (int i = 0; i < length; i++)
    {

        if (str1[i] == splitter)
        {
            str2[*count][str2_index] = '\0';
            str2_index = 0;
            (*count)++;
        }
        else
        {
            str2[*count][str2_index] = str1[i];
            str2_index++;
        }
    }

    str2[*count][str2_index] = '\0';
    for (int i = 0; i <= *count; i++)
    {
        printf("str2[%d] = \"%s\"\n", i, str2[i]);
    }
}
