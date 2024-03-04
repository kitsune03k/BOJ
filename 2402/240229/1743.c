#include <stdio.h>
#include <stdbool.h>

bool arr[100][100];
bool checked[100][100];

int search(int i, int j, int row, int col, char dir) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == true) { // 쓰레기 있으면
        /*** 체크가 안됐을 시에만 작동해야됨!!!! 안그러면 무한재귀로 메모리 초과!!!! ***/
        checked[i][j] = true;
        ret += 1;

        switch(dir) {
            case 'E':
                ret += search(i, j + 1, row, col, 'E');

                ret += search(i + 1, j, row, col, 'S');
                ret += search(i - 1, j, row, col, 'N');
                break;
            case 'N':
                ret += search(i - 1, j, row, col, 'N');

                ret += search(i, j + 1, row, col, 'E');
                ret += search(i, j - 1, row, col, 'W');
                break;
            case 'W':
                ret += search(i, j - 1, row, col, 'W');

                ret += search(i + 1, j, row, col, 'S');
                ret += search(i - 1, j, row, col, 'N');
                break;
            case 'S':
                ret += search(i + 1, j, row, col, 'S');

                ret += search(i, j + 1, row, col, 'E');
                ret += search(i, j - 1, row, col, 'W');
                break;

            default:
                ret += search(i, j + 1, row, col, 'E');
                ret += search(i - 1, j, row, col, 'N');
                ret += search(i, j - 1, row, col, 'W');
                ret += search(i + 1, j, row, col, 'S');
        }
    }

    return ret;
}

int main(void) {
    int row, col, k;
    scanf("%d %d %d", &row, &col, &k);
    getchar();

    int r, c;
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &r, &c);
        arr[r - 1][c - 1] = true;
        getchar();
    }
/*
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
*/
    int max = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int count = 0;

            if(checked[i][j] == false && arr[i][j] == true) {
                count = search(i, j, row, col, 0);
                //printf("[%d][%d] : %d\n", i, j, count);

                if(count > max) {
                    max = count;
                }
            }
        }
    }

    printf("%d", max);
}