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

int arr[25][25];
bool checked[25][25];

int dfs(int i, int j, int row, int col) {
    if(i < 0 || i >= row || j < 0 || j >= col){
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == 1){
        checked[i][j] = true;
        ret += 1;

        ret += dfs(i-1, j, row, col);
        ret += dfs(i+1, j, row, col);
        ret += dfs(i, j-1, row, col);
        ret += dfs(i, j+1, row, col);
    }

    return ret;
}


int main(void) {
    int n;

    scanf("%d", &n);
    getchar();

    int pcount = 0;

    char tmp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%c", &tmp);
            arr[i][j] = tmp - '0';
        }
        getchar();
    }

    int maxarea = n*n/2 + 1;
    int ans[maxarea];
    memset(ans, 0, sizeof(int) * maxarea);


    int ret;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ret = dfs(i, j, n, n);
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
            printf("%d\n", ans[i]);
        }
    }

}