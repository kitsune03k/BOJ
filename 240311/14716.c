#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

char arr[250][250];
bool checked[250][250];

int dfs(int i, int j, int row, int col) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == '1') {
        checked[i][j] = true;
        ret += 1;

        ret += dfs(i - 1, j, row, col);
        ret += dfs(i + 1, j, row, col);
        ret += dfs(i, j - 1, row, col);
        ret += dfs(i, j + 1, row, col);
        ret += dfs(i - 1, j - 1, row, col);
        ret += dfs(i - 1, j + 1, row, col);
        ret += dfs(i + 1, j - 1, row, col);
        ret += dfs(i + 1, j + 1, row, col);
    }

    return ret;
}


int main(void) {
    int row, col;

    scanf("%d %d", &row, &col);
    getchar();

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%c", &arr[i][j]);
            getchar();
        }
    }

    int pcount = 0;
    int ret;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            ret = dfs(i, j, row, col);
            //printf("dfs[%d][%d] = %d\n", i, j, ret);

            if(ret != 0) {
                pcount++;
            }
        }
    }

    printf("%d", pcount);


}