#include <stdio.h>
#include <stdbool.h>

bool arr[101][101];

int main(void)
{
    int xmin, ymin, xmax, ymax;

    for(int t=0; t<4; t++){
        scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
        getchar();

        for(int i=xmin; i<xmax; i++){
            for(int j=ymin; j<ymax; j++){
                arr[i][j] = true;
            }
        }
    }

    int truecount = 0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(arr[i][j])
                truecount++;
        }
    }

    printf("%d", truecount);

    return 0;

}