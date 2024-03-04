#include <stdio.h>
#include <stdlib.h>

unsigned long long *rpre2;
unsigned long long *rpre1;
unsigned long long *rcurr;

unsigned long long rascal(int n, int m)
{
    unsigned long long ret;

    rpre2 = (unsigned long long *)malloc(sizeof(unsigned long long) * 1);
    rpre2[0] = 1;

    rpre1 = (unsigned long long *)malloc(sizeof(unsigned long long) * 2);
    rpre1[0] = 1;
    rpre1[1] = 1;

    for(int i = 2; i <= n; i++) {
        rcurr = (unsigned long long *)malloc(sizeof(unsigned long long) * (i+1));

        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                rcurr[j] = 1;
            }
            else {
                rcurr[j] = (rpre1[j - 1] * rpre1[j] + 1) / rpre2[j - 1];
            }
        }

        if(i == n)
            ret = rcurr[m];

        free(rpre2);
        rpre2 = rpre1;
        rpre1 = rcurr;
    }
    free(rpre1);
    free(rpre2);

    return ret;
}

int main(void) {


    int T;
    scanf("%d", &T);
    getchar();

    unsigned long long* answer = (unsigned long long*)malloc(sizeof(unsigned long long)*T);

    int N, M;
    for(int i=0; i<T; i++){
        scanf("%d %d", &N, &M);
        answer[i] = rascal(N, M);
    }

    for(int i=0; i<T; i++){
        printf("%llu\n", answer[i]);
    }

    free(answer);

    return 0;

}