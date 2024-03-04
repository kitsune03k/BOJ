#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    char stars[n][n];

    int lines = 2*n-1;

    for(int i=0; i<lines; i++)
    {
        int llen, nlen, slen; // 전체, 빈칸, 별 갯수

        if(i < n)
        {
            llen = n + i;
            nlen = (n - 1) - i;
            slen = llen - nlen;

            for(int j=0; j<nlen; j++)
            {
                printf(" ");
            }
            for(int j=0; j<slen; j++)
            {
                printf("*");
            }
        }
        else // i >= n
        {
            llen = lines + (n-1-i);
            nlen = (i + 1) - n;
            slen = llen - nlen;

            for(int j=0; j<nlen; j++)
            {
                printf(" ");
            }
            for(int j=0; j<slen; j++)
            {
                printf("*");
            }
        }
        printf("\n");
    }
}
