#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();

    char rectangle[N][M];
    for(int i=0; i<N; i++){
        scanf("%s", rectangle[i]);
    }

    int sqmax;
    if(N < M)
        sqmax = N;
    else
        sqmax = M;

    int sqidx = -1;
    for(int sqlen = 1; sqlen <= sqmax; sqlen++) {
        bool find = false;

        for(int i = 0; i < N - sqlen + 1; i++) {
            for(int j = 0; j < M - sqlen + 1; j++) {

                int ref = rectangle[i][j];
                int val1 = rectangle[i + sqlen-1][j];
                int val2 = rectangle[i][j + sqlen-1];
                int val3 = rectangle[i + sqlen-1][j + sqlen-1];

                if(ref == val1 && ref == val2 && ref == val3) {
                    find = true;
                    sqidx = sqlen;
                    break;
                }
            }
            if(find == true)
                break;
        }
    }

    printf("%d", sqidx*sqidx);

}