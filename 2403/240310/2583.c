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

int arr[100][100];
bool checked[100][100];

int dfs(int i, int j, int row, int col) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == 0) {
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
    int row, col, n;

    scanf("%d %d %d", &row, &col, &n);
    getchar();

    int r1, c1, r2, c2;
    for(int c = 0; c < n; c++) {
        scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
        getchar();

        for(int i = r1; i < r2; i++) {
            for(int j = c1; j < c2; j++) {
                arr[i][j] = 1;
            }
        }
    }

    int maxarea = row*col/2 + 1;
    int ans[maxarea];
    memset(ans, 0, sizeof(int) * maxarea);

    int pcount = 0;

    int ret;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            ret = dfs(i, j, row, col);
            //printf("dfs[%d][%d] = %d\n", i, j, ret);

            if(ret != 0) {
                ans[pcount++] = ret;
            }
        }
    }

    qsort(ans, maxarea, sizeof(int), cmp);

    printf("%d\n", pcount);
    for(int i=0; i<maxarea; i++){
        if(ans[i] != 0){
            printf("%d ", ans[i]);
        }
    }

}