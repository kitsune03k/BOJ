#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, K; // N의 K번째 약수

    scanf("%d %d", &N, &K);

    int* yaksu = (int*)calloc(sizeof(int), N);
    int count = 0;

    // 약수 찾기
    for(int i=1; i<=N; i++){
        if(N%i == 0) {
            *(yaksu+count++) = i;
        }
    }

    printf("%d", yaksu[K-1]);

    return 0;
}