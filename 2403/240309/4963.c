#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

int row;
int col;
int arr[50][50];
bool checked[50][50];

bool dfs(int i, int j) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return false;
    }
    else {
        if(checked[i][j] == false && arr[i][j] == 1) {
            checked[i][j] = true;

            dfs(i, j + 1);
            dfs(i - 1, j + 1);
            dfs(i - 1, j);
            dfs(i - 1, j - 1);
            dfs(i, j - 1);
            dfs(i + 1, j - 1);
            dfs(i + 1, j);
            dfs(i + 1, j + 1);

            return true;
        }
        else{
            return false;
        }
    }
}

int main(void) {
    int *ans = (int *) calloc(sizeof(int), 100);

    int t;
    for(t = 0;; t++) {
        memset(arr, false, sizeof(bool) * 50 * 50);
        memset(checked, false, sizeof(bool) * 50 * 50);

        scanf("%d %d", &col, &row);
        getchar();

        if(row == 0 && col == 0) {
            break;
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                scanf("%d", &arr[i][j]);
                getchar();
            }
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                ans[t] += dfs(i, j);
            }
        }
    }

    for(int i = 0; i < t; i++) {
        printf("%d\n", ans[i]);
    }

    free(ans);

}