#include <stdio.h>
#include <stdbool.h>

char arr[1000][1000];
char checked[1000][1000];

int row, col;

void dfs(int i, int j) {
    if(i < 0 || i >= row || j < 0 || j >= col) {
        return;
    }

    if(arr[i][j] == '1') {
        return;
    }

    if(checked[i][j] == false && arr[i][j] == '0') {
        checked[i][j] = true;

        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    }
}

int main(void) {
    char *ny[2] = {"NO", "YES"};

    scanf("%d %d", &row, &col);
    getchar();

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }

    for(int j = 0; j < col; j++) {
        dfs(0, j);
    }

    /*
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d", checked[i][j]);
        }
        printf("\n");
    }
     */

    bool elec = false;
    for(int i = 0; i < col; i++) {
        if(checked[row - 1][i] == true) {
            elec = true;
        }
    }

    printf("%s", ny[elec]);


}