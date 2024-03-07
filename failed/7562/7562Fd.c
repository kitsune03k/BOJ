#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

int arr[300][300];

void knight(int r, int c, int len, int t) { // 딱!! 8개중에 조건맞는거만 움직인다!!!
    if(r - 1 >= 0 && c - 2 >= 0) {
        if(arr[r - 1][c - 2] == -1) {
            arr[r - 1][c - 2] = t;
        }
    }
    if(r - 1 >= 0 && c + 2 < len) {
        if(arr[r - 1][c + 2] == -1) {
            arr[r - 1][c + 2] = t;
        }
    }
    if(r + 1 < len && c - 2 >= 0) {
        if(arr[r + 1][c - 2] == -1) {
            arr[r + 1][c - 2] = t;
        }
    }
    if(r + 1 < len && c + 2 < len) {
        if(arr[r + 1][c + 2] == -1) {
            arr[r + 1][c + 2] = t;
        }
    }
    if(r - 2 >= 0 && c - 1 >= 0) {
        if(arr[r - 2][c - 1] == -1) {
            arr[r - 2][c - 1] = t;
        }
    }
    if(r - 2 >= 0 && c + 1 < len) {
        if(arr[r - 2][c + 1] == -1) {
            arr[r - 2][c + 1] = t;
        }
    }
    if(r + 2 < len && c - 1 >= 0) {
        if(arr[r + 2][c - 1] == -1) {
            arr[r + 2][c - 1] = t;
        }
    }
    if(r + 2 < len && c + 1 < len) {
        if(arr[r + 2][c + 1] == -1) {
            arr[r + 2][c + 1] = t;
        }
    }
}

//for debug
void show(int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    getchar();

    int ans[t];

    int l; // 체스판의 길이
    int row1, col1; // 시작지점
    int row2, col2; // 목표지점
    for(int c = 0; c < t; c++) { // 각 test case
        memset(arr, -1, sizeof(int) * 300 * 300);
        scanf("%d", &l);
        getchar();

        scanf("%d %d", &row1, &col1);
        getchar();
        scanf("%d %d", &row2, &col2);
        getchar();

        arr[row1][col1] = 0;

        for(int m = 0; m < l; m++) {
            printf("*** m = %d ***\n", m);
            for(int i = 0; i < l; i++) {
                for(int j = 0; j < l; j++) {
                    if(arr[i][j] == m) {
                        printf("[%d][%d] %d eureka!!\n", i, j, m);
                        knight(i, j, l, m + 1); // 갈 수 있는 8개만 확장!!
                        // checked가 필요가 없는것이, arr[i][j]가 어차피 -1이면 칠해야 하는거고 -1이 아니면 칠하면 안됨.
                    }
                }
            }
            show(l);
            printf("\n");
        }
        ans[c] = arr[row2][col2];
    }


    for(int i = 0; i < t; i++) {
        printf("%d\n", ans[i]);
    }
}