#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);
    getchar();

    char arr[M][N];
    char times[M-7][N-7];

    //printf("%lu\n", sizeof(times));
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

    for(int row = 0; row < M-7; row++) {
        for(int col = 0; col < N-7 ; col++) {
            int case1 = 0, case2 = 0; // 좌상단 흰, 검

            for(int i = row; i < row+8; i++) {
                for(int j = col; j < col+8; j++) {
                    if((i + j) % 2) { // 대각선 홀수열
                        if(arr[i][j] != 'B') { // 홀수열이 B가 아니면
                            case1++;
                        }
                        else {
                            case2++;
                        }
                    }
                    else { // 대각선 짝수열
                        if(arr[i][j] != 'W') {
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

    for(int i=0; i<M-7; i++){
        for(int j=0; j<N-7; j++){
            if(times[i][j] < answer)
                answer = times[i][j];
        }
    }

    printf("%d", answer);

    return 0;

}