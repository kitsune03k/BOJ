#include <stdio.h>

int main(void)
{
    int pic[100][100] = {0,};

    int N, M;
    scanf("%d %d", &N, &M);
    getchar();


    int points[N][4];
    for(int i=0; i<N; i++){
        for(int j=0; j<4; j++) {
            scanf("%d", &points[i][j]);
            points[i][j] -= 1;
        }
    }

    for(int n=0; n<N; n++){
        for(int i=points[n][0]; i<=points[n][2]; i++){
            for(int j=points[n][1]; j<=points[n][3]; j++){
                pic[i][j]++;
            }
        }
    }

    int answer = 0;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(pic[i][j] > M)
                answer++;
        }
    }

    printf("%d", answer);

    return 0;

}