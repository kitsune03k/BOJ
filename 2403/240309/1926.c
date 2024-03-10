#include <stdio.h>
#include <stdbool.h>

int arr[500][500];
bool checked[500][500];

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
    int row, col;

    scanf("%d %d", &row, &col);
    getchar();

    int pcount = 0, pmaxsz = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
            getchar();
        }
    }

    int ret;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            ret = dfs(i, j, row, col);

            if(ret != 0) {
                if(ret > pmaxsz) {
                    pmaxsz = ret;
                }
                pcount++;
            }
        }
    }

    printf("%d", pcount);

}