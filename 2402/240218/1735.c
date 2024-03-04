#include <stdio.h>

int main(void)
{
    int arr[2][2];
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    getchar();

    int bunja, bunmo;

    bunmo = arr[0][1]*arr[1][1];
    bunja = arr[0][0]*arr[1][1] + arr[1][0]*arr[0][1];

    for(int div = 2; div <= bunmo;){
        if(bunmo % div == 0 && bunja % div == 0){
            bunmo /= div;
            bunja /= div;
        }
        else{
            div++;
        }
    }
    printf("%d %d", bunja, bunmo);
}