#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// ascii A-Z 65-90, a-z 97-122

int main(void)
{
    char* arr = (char*)calloc(sizeof(char), 1000001);
    scanf("%s", arr);

    int abc[2][26] = {0,};

    int slen = strlen(arr);
    for(int i = 0; i<slen; i++)
    {
        // 소문자일경우
        if(arr[i] > 90)
        {
            arr[i] -= 32; // 대문자화
        }
        abc[0][arr[i] - 'A']++;
    }

    int max = -1;

    for(int i = 0; i < 26; i++)
    {
        if(abc[0][i] >= max)
        {
            max = abc[0][i];
        }
    }

    char answer = 0;
    int maxcount = 0;

    for(int i = 0; i < 26; i++)
    {
        if(abc[0][i] == max)
        {
            maxcount++;
            abc[1][i] = 1;
        }
    }

    if(maxcount > 1)
    {
        answer = '?';
    }
    else
    {
        for(int i = 0; i < 26; i++)
        {
            if(abc[1][i] == true)
            {
                answer = i+65;
            }
        }
    }

    printf("%c", answer);

    return 0;

}