#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    getchar();

    char arr[M][N];
    char times[M-K+1][N-K+1];

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = 0;
        }
    }

    for(int i=0; i<M; i++){
        scanf("%s", arr[i]);
    }

    /***
     * case1. 좌상단이 흰색일경우
     * 대각선 짝수열 W
     * 대각선 홀수열 B
     *
     * case2. 좌상단이 검은색일경우
     * 대각선 짝수열 B
     * 대각선 홀수열 W
     ***/

    for(int row = 0; row <= M-K; row++) {
        for(int col = 0; col <= N-K ; col++) {
            int case1 = 0, case2 = 0; // 좌상단 흰, 검

            for(int i = row; i < row+K; i++) {
                for(int j = col; j < col+K; j++) {
                    if((i + j) % 2) { // 대각선 홀수열
                        if(arr[i][j] != 'B') { // 홀수열이 B가 아니면
                            case1++;
                        }
                        else {
                            case2++;
                        }
                    }
                    else { // 대각선 짝수열
                        if(arr[i][j] != 'W') { // 짝수열이 W가 아니면
                            case1++;
                        }
                        else {
                            case2++;
                        }
                    }
                }
            }

            times[row][col] = case1 < case2 ? case1 : case2;
        }
    }

    int answer = 2000000000;

    for(int i=0; i<=M-K; i++){
        for(int j=0; j<=N-K; j++){
            if(times[i][j] < answer)
                answer = times[i][j];
        }
    }

    printf("%d", answer);

    return 0;

}