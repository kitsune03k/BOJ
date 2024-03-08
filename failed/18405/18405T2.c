#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

int arr[200][200];
bool starteven[200][200];
bool startodd[200][200];

bool checked[200][200]; // 이번 t에 건들지마!

// 바이러스가 있고, 아직 체크되지 않은곳의 좌표만 전달됨이 보장
void infect(int i, int j, int row, int col, bool iseven) {
    bool (*curstart)[200];
    bool (*nextstart)[200];

    if(iseven) {
        curstart = starteven;
        nextstart = startodd;
    }
    else {
        curstart = startodd;
        nextstart = starteven;
    }

    if(i - 1 >= 0) {
        if(checked[i - 1][j] == false && curstart[i - 1][j] == false) {
            arr[i - 1][j] = arr[i][j];
            checked[i - 1][j] = true;
            nextstart[i - 1][j] = true;
        }

    }
    if(i + 1 < row) {
        if(checked[i + 1][j] == false && curstart[i + 1][j] == false) {
            arr[i + 1][j] = arr[i][j];
            checked[i + 1][j] = true;
            nextstart[i + 1][j] = true;
        }
    }
    if(j - 1 >= 0) {
        if(checked[i][j - 1] == false && curstart[i][j - 1] == false) {
            arr[i][j - 1] = arr[i][j];
            checked[i][j - 1] = true;
            nextstart[i][j - 1] = true;
        }

    }
    if(j + 1 < col) {
        if(checked[i][j + 1] == false && curstart[i][j + 1] == false) {
            arr[i][j + 1] = arr[i][j];
            checked[i][j + 1] = true;
            nextstart[i][j + 1] = true;
        }
    }
}

void show1(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void showstarteven(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", starteven[i][j]);
        }
        printf("\n");
    }
}

void showstartodd(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", startodd[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n, k; // 크기, 바이러스 종류
    scanf("%d %d", &n, &k);
    getchar();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            getchar();
        }
    }

    int s, y, x; // 초, 원하는 좌표 (row, col);
    scanf("%d %d %d", &s, &y, &x);
    getchar();
    y--;
    x--;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] != 0) {
                starteven[i][j] = true;
            }
        }
    }

    for(int t = 0; t < s; t++) {
        memset(checked, false, sizeof(bool) * 200 * 200);

        bool (*curstart)[200];
        bool (*nextstart)[200];

        bool iseven = t % 2 == 0 ? true : false;

        if(iseven) {
            curstart = starteven;
            nextstart = startodd;
        }
        else {
            curstart = starteven;
            nextstart = starteven;
        }

        for(int virus = 1; virus <= k; virus++) {
            for(int i = 0; i < n; i++) { // row
                for(int j = 0; j < n; j++) { // column
                    if(arr[i][j] == virus) {
                        if(arr[i][j] == virus) {
                            if(curstart[i][j] == true) {
                                checked[i][j] = true;
                                nextstart[i][j] = true;
                                infect(i, j, n, n, iseven);
                            }
                        }
                    }
                }
            }
        }
    }


    printf("%d", arr[y][x]);


}