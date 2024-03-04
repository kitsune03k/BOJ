#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

void search(int i, int j, int N, bool (*checked)[N], bool (*barr)[N], char dir)
{
    // 위치 유효 검즘
    if(i < 0 || i >= N || j < 0 || j >= N)
        return;

    if(barr[i][j] == true) {// 안전한 땅이면
        if(checked[i][j] == false) {
            checked[i][j] = true;

            switch(dir) {
                case 'E':
                    search(i, j + 1, N, checked, barr, 'E');

                    search(i + 1, j, N, checked, barr, 'S');
                    search(i - 1, j, N, checked, barr, 'N');
                    break;
                case 'W':
                    search(i, j - 1, N, checked, barr, 'W');

                    search(i + 1, j, N, checked, barr, 'S');
                    search(i - 1, j, N, checked, barr, 'N');
                    break;
                case 'S':
                    search(i + 1, j, N, checked, barr, 'S');

                    search(i, j + 1, N, checked, barr, 'E');
                    search(i, j - 1, N, checked, barr, 'W');
                    break;
                case 'N':
                    search(i - 1, j, N, checked, barr, 'N');

                    search(i, j + 1, N, checked, barr, 'E');
                    search(i, j - 1, N, checked, barr, 'W');
                    break;
                default:
                    search(i, j + 1, N, checked, barr, 'E');
                    search(i, j - 1, N, checked, barr, 'W');
                    search(i + 1, j, N, checked, barr, 'S');
                    search(i - 1, j, N, checked, barr, 'N');
            }
        }
    }
    else{ //안전하지 않은 땅이면
        return;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    getchar();

    int harr[N][N];

    int hmax = -1;
    memset(harr, 0, sizeof(int)*N*N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            scanf("%d", &harr[i][j]);
            if(harr[i][j] > hmax)
                hmax = harr[i][j];
        }
    }

    bool barr[hmax][N][N]; // true = 안전, false = 사망
    memset(barr, true, sizeof(bool)*hmax*N*N);

    for(int k=0; k<hmax; k++){ // 높이
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(harr[i][j] <= k){ // 수위보다 높이가 낮거나 같으면
                    barr[k][i][j] = false; // 사망
                }
            }
        }
    }

    bool checked[N][N]; // 안전한 영역만 체크
    int safezone[hmax]; // 각 높이당 안전영역 갯수

    for(int k=0; k<hmax; k++){ // 높이
        memset(checked, false, sizeof(bool)*N*N);
        safezone[k] = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(checked[i][j] == false) { // 체크하지 않은 영역일경우
                    if(barr[k][i][j] == true) {
                        search(i, j, N, checked, barr[k], 0);
                        safezone[k]++;
                    }
                }
            }
        }
    }

    int answer = -1;
    for(int i=0; i<hmax; i++){
        if(safezone[i] > answer)
            answer = safezone[i];
    }

    printf("%d", answer);
}