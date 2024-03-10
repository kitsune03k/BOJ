#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

int cmp(const void *x1, const void *x2) {
    int i1 = *(int *) x1, i2 = *(int *) x2;

    if(i1 == i2) {
        return 0;
    }
    else {
        if(i1 > i2) {
            return 1;
        }
        else {
            return -1;
        }
    }
}

char arr[100][100];
bool checked[100][100];

int dfs(int i, int j, int row, int col) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == '#') {
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
    int t;

    scanf("%d", &t);
    getchar();

    int ans[t];

    int row, col;
    for(int c = 0; c < t; c++) {
        memset(arr, 0, sizeof(char) * 100 * 100);
        memset(checked, false, sizeof(bool) * 100 * 100);
        scanf("%d %d", &row, &col);
        getchar();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                scanf("%c", &arr[i][j]);
            }
            getchar();
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

        ans[c] = pcount;
    }

    for(int c=0; c<t; c++){
        printf("%d\n", ans[c]);
    }

}