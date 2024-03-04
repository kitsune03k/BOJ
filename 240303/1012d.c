#include <stdio.h>
#include <stdbool.h>
#include <memory.h>


int search(int i, int j, int row, int col, bool arr[][col], bool checked[][col], char dir) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == true) {
        /*** 체크가 안됐을 시에만 작동해야됨!!!! 안그러면 무한재귀로 메모리 초과!!!! ***/
        checked[i][j] = true;
        ret += 1;

        switch(dir) {
            case 'E':
                ret += search(i, j + 1, row, col, arr, checked, 'E');

                ret += search(i + 1, j, row, col, arr, checked, 'S');
                ret += search(i - 1, j, row, col, arr, checked, 'N');
                break;
            case 'N':
                ret += search(i - 1, j, row, col, arr, checked, 'N');

                ret += search(i, j + 1, row, col, arr, checked, 'E');
                ret += search(i, j - 1, row, col, arr, checked, 'W');
                break;
            case 'W':
                ret += search(i, j - 1, row, col, arr, checked, 'W');

                ret += search(i + 1, j, row, col, arr, checked, 'S');
                ret += search(i - 1, j, row, col, arr, checked, 'N');
                break;
            case 'S':
                ret += search(i + 1, j, row, col, arr, checked, 'S');

                ret += search(i, j + 1, row, col, arr, checked, 'E');
                ret += search(i, j - 1, row, col, arr, checked, 'W');
                break;

            default:
                ret += search(i, j + 1, row, col, arr, checked, 'E');
                ret += search(i - 1, j, row, col, arr, checked, 'N');
                ret += search(i, j - 1, row, col, arr, checked, 'W');
                ret += search(i + 1, j, row, col, arr, checked, 'S');
        }
    }

    return ret;
}

//for debug
void showbarr(int row, int col, bool arr[][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    getchar();

    int ans[t];

    int m, n, k;
    for(int c = 0; c < t; c++) {
        scanf("%d %d %d", &m, &n, &k); // 밭 크기, 배추 갯수
        getchar();

        bool arr[m][n];
        bool checked[m][n];

        memset(arr, false, sizeof(bool)*m*n);
        memset(checked, false, sizeof(bool)*m*n);

        int p, q;
        for(int i=0; i<k; i++){
            // 배추 위치
            scanf("%d %d", &p, &q);
            getchar();
            arr[p][q] = true;
        }
        printf("*** baechoo farm ***\n");
        showbarr(m, n, arr);
        printf("\n\n");

        int rslt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int ret = -1;

                if(checked[i][j] == false && arr[i][j] == true){
                    ret = search(i, j, m, n, arr, checked, 0);

                    if(ret > 0)
                        rslt++;
                }

                printf("[%d][%d]\n", i, j);
                showbarr(m, n, checked);
                printf("ret = %d, rslt = %d\n\n", ret, rslt);
            }
        }

        ans[c] = rslt;
    }

    for(int i=0; i<t; i++){
        printf("%d\n", ans[i]);
    }

}