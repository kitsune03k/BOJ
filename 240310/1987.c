#include <stdio.h>

char arr[20][20];

int main(void){
    int row, col;
    scanf("%d %d", &row, &col);
    getchar();

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }


}