#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// ascii a-z = 97-122
// 연속단어인지 탐색
int gw(char w[])
{
    int wlen = strlen(w);

    int abc[26] = {0,};
    bool fin[26] = {0,};

    for(int i=0; i<wlen; i++)
    {
        int idx = w[i] - 'a'; // 0~25;

        if(fin[idx] == true)
        {
            return 0;
        }

        if(w[i] != w[i+1])
            fin[idx] = true;

    }

    return 1;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    char* words[n];

    for(int i=0; i<n; i++)
    {
        char* newword = (char*)calloc(sizeof(char),101);
        scanf("%s", newword);
        words[i] = newword;
    }

    int answer = 0;
    for(int i=0; i<n; i++)
    {
        answer += gw(words[i]);
    }

    printf("%d", answer);

}