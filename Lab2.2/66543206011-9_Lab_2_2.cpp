#include <stdio.h>
#include <string.h>

char* reverse(char str1[]);

int main()
{
    char text[50] = "I Love You";
    char *out;
    out = reverse(text);
    printf(out);
}


char* reverse(char str1[]) {
     int length = strlen(str1);

    char *str2 = new char[length + 1]; 

    for (int i = 0; i < length; i++) {
        str2[i] = str1[length - 1 - i];
    }
    str2[length] = '\0';

    return str2;
}