#include <stdio.h>
#include <string.h>

// B를 x번 곱함
int power(int B, int x)
{
    if(x == 0)
        return 1;

    int ret = 1;
    for(int i=0; i<x; i++)
    {
        ret *= B;
    }

    return ret;
}

/*
 * 0~9 = 48~57
 * A~Z = 65~90
 */
int ctoi(char c)
{
    int ret = 0;

    if(c >= 'A' && c <= 'Z')
        ret = (int)(c - 'A') + 10;
    else if(c >= '0' && c <= '9')
        ret = (int)(c - '0');

    return ret;
}

int main(void)
{
    char N[36]; // B진수 str
    int B; // 10진수

    scanf("%s %d", N, &B);
    int slen = strlen(N);

    int answer = 0;

    for(int i=0; i<slen; i++){
        int idx = (slen-1) - i;
        answer += ( ctoi(N[i]) * power(B, idx));
    }

    printf("%d", answer);

    return 0;
}