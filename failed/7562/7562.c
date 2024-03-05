#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

int arr[300][300];
bool checked[300][300];

void knight(int row, int col, int len, int times){ // 시작점의 좌표
    if(row < 0 || row >=len || col < 0 || col >= len){
        return;
    }

    if(checked[row][col] == false){
        checked[row][col] = true;
        arr[row][col] = times++;

        knight(row + 1, col + 2, len, times);
        knight(row + 2, col + 1, len, times);
        knight(row + 2, col - 1, len, times);
        knight(row + 1, col - 2, len, times);
        knight(row - 1, col - 2, len, times);
        knight(row - 2, col - 1, len, times);
        knight(row - 2, col + 1, len, times);
        knight(row - 1, col + 2, len, times);
    }
}

//for debug
void show(int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    getchar();

    int ans[t];

    int l, row1, col1, row2, col2;
    for(int i=0; i<t; i++){
        memset(arr, 0, 300*300);
        memset(checked, false, 300*300);
        scanf("%d", &l);
        getchar();

        scanf("%d %d", &row1, &col1);
        getchar();
        scanf("%d %d", &row2, &col2);
        getchar();

        knight(row1, col1, l, 0);

        ans[i] = arr[row2][col2];
        show(l);
    }


    for(int i=0; i<t; i++){
        printf("%d\n", ans[i]);
    }
}