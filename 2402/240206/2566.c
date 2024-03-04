#include <stdio.h>

int main(void)
{
    int arr[9][9];

    for(int i=0; i<9; i++){
        scanf("%d %d %d %d %d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4], &arr[i][5],
              &arr[i][6], &arr[i][7], &arr[i][8]);
    }

    int max = 0, x = 0, y = 0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j] >= max){
                max = arr[i][j];
                x = i+1;
                y = j+1;
            }
        }
    }

    printf("%d\n%d %d", max, x, y);

    return 0;
}