#include <stdio.h>

int main(void)
{
    char* arr[6] = {"         ,r\'\"7", "r`-_   ,\'  ,/", " \\. \". L_r\'", "   `~\\/", "      |", "      |"};

    for(int i=0; i<6; i++)
    {
        printf("%s", arr[i]);
        printf("\n");
    }

    return 0;

}
