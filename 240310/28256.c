#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

char arr[3][3];
bool checked[3][3];

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

int dfs(int i, int j, int row, int col) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    if(i == 1 && j == 1) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == 'O') {
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
    int iasz[4]; // 입력받은 각 영역 크기
    int iacount = 0; // 입력받은 영역 갯수 (갱신 x)

    int dasz[4]; // dfs로 나온 각 영역 크기 - 최대 4개 구분된 영역 존재 가능, 추후 정렬
    int dacount = 0; // dfs로 나온 영역 갯수 (갱신 o)

    int t;
    scanf("%d", &t);
    getchar();

    bool ans[t];


    for(int c = 0; c < t; c++) {
        memset(arr, 0, sizeof(char) * 3 * 3);
        memset(checked, 0, sizeof(bool) * 3 * 3);

        memset(iasz, 0, sizeof(int) * 4);
        iacount = 0;

        memset(dasz, 0, sizeof(int) * 4);
        dacount = 0;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                scanf("%c", &arr[i][j]);
            }
            getchar();
        }

        scanf("%d", &iacount);
        getchar();

        for(int i = 0; i < iacount; i++) {
            scanf("%d", &iasz[i]);
            getchar();
        }

        int ret;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                ret = dfs(i, j, 3, 3);

                if(ret != 0) {
                    dasz[dacount++] = ret;
                }
            }
        }
        qsort(iasz, 4, sizeof(int), cmp);
        qsort(dasz, 4, sizeof(int), cmp);

        bool ansc = true;

        // 판단
        if(iacount != dacount) {
            ansc = false;
        }
        else{
            for(int i=0; i<4; i++){
                if(iasz[i] != dasz[i]){
                    ansc = false;
                    break;
                }
            }
        }

        ans[c] = ansc;
    }

    for(int c = 0; c < t; c++) {
        printf("%d\n", ans[c]);
    }
}