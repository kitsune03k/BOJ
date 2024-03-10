#include <stdio.h>
#include <stdbool.h>

int row;
int col;
char arr[123][123];
bool checked[123][123];

int dfsw(int i, int j) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == 'W') {
        checked[i][j] = true;
        ret += 1;

        ret += dfsw(i - 1, j);
        ret += dfsw(i + 1, j);
        ret += dfsw(i, j - 1);
        ret += dfsw(i, j + 1);
    }

    return ret;
}

int dfsb(int i, int j) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false && arr[i][j] == 'B') {
        checked[i][j] = true;
        ret += 1;

        ret += dfsb(i - 1, j);
        ret += dfsb(i + 1, j);
        ret += dfsb(i, j - 1);
        ret += dfsb(i, j + 1);
    }

    return ret;
}

int main(void) {
    scanf("%d %d", &col, &row);
    getchar();

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }

    int wpower = 0, bpower = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int tmpw = dfsw(i, j);
            int tmpb = dfsb(i, j);

            wpower += tmpw*tmpw;
            bpower += tmpb*tmpb;
        }
    }

    printf("%d %d", wpower, bpower);
}