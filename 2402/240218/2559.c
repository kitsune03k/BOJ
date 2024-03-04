#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);

    long long* Narr = (long long*)calloc(sizeof(long long), N+1);
    Narr[0] = 0;

    for(int i=1; i<=N; i++){
        scanf("%lld", &Narr[i]);
        Narr[i] += Narr[i-1];
    }
    getchar();

    int days = N-K+1;
    long long answer = -101;

    long long Ksum;
    for(int i=0; i<days; i++){
        Ksum = Narr[i+K]-Narr[i];
        if(Ksum >= answer) {
            answer = Ksum;
        }
    }

    printf("%lld", answer);

    free(Narr);

    return 0;
}