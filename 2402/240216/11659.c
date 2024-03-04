#include <stdio.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();

    int Narr[N+1];
    Narr[0] = 0;

    for(int i=1; i<=N; i++){
        scanf("%d", &Narr[i]);
        Narr[i] += Narr[i-1];
    }
    getchar();

    int Marr[M][2];

    for(int i=0; i<M; i++){
        scanf("%d %d", &Marr[i][0], &Marr[i][1]);
    }
    getchar();

    for(int i=0; i<M; i++){
        printf("%d\n", Narr[Marr[i][1]]-Narr[Marr[i][0]-1]);
    }
}