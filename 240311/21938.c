#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

int arr[1000][1000];
bool arr2[1000][1000];
bool checked[1000][1000];

int dfs(int i, int j, int row, int col) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr2[i][j] == true) {
        checked[i][j] = true;
        ret += 1;

        ret += dfs(i - 1, j, row, col);
        ret += dfs(i + 1, j, row, col);
        ret += dfs(i, j - 1, row, col);
        ret += dfs(i, j + 1, row, col);
    }

    return ret;
}


int main(void) {
    int row, col;

    scanf("%d %d", &row, &col);
    getchar();

    int r, g, b;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d %d %d", &r, &g, &b);
            getchar();
            arr[i][j] = r+g+b;
        }
    }

    int threshold;
    scanf("%d", &threshold);
    threshold *= 3;
    getchar();

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(arr[i][j] >= threshold){
                arr2[i][j] = true;
            }
        }
    }


    int pcount = 0;
    int ret;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            ret = dfs(i, j, row, col);

            if(ret != 0) {
                pcount++;
            }
        }
    }

    printf("%d", pcount);

}