#include <stdio.h>
#include <stdbool.h>

char arr[600][600];
bool checked[600][600];

int search(int i, int j, int row, int col){
    if(i < 0 || i >= row || j < 0 || j >= col || arr[i][j] == 'X'){
        return 0;
    }

    int ret = 0;

    if(checked[i][j] == false){
        checked[i][j] = true;

        if(arr[i][j] == 'P'){
            ret++;
        }

        ret += search(i+1, j, row, col);
        ret += search(i, j+1, row, col);
        ret += search(i-1, j, row, col);
        ret += search(i, j-1, row, col);
    }

    return ret;
}


int main(void){
    int row, col;
    scanf("%d %d", &row, &col);
    getchar();

    int di, dj;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%c", &arr[i][j]);

            if(arr[i][j] == 'I'){
                di = i;
                dj = j;
            }
        }
        getchar();
    }

    int ans = search(di, dj, row, col);

    if(ans != 0)
        printf("%d", ans);
    else
        printf("TT");

}