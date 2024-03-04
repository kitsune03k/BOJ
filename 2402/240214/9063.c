#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int* xpos = (int*)calloc(sizeof(int), N);
    int* ypos = (int*)calloc(sizeof(int), N);
    for(int i=0; i<N; i++){
        scanf("%d %d", xpos+i, ypos+i); // x, y
        getchar();
    }

    int xmin = 10001, xmax = -10001, ymin = 10001, ymax = -10001;

    for(int i=0; i<N; i++){
        if(xpos[i] > xmax)
            xmax = xpos[i];
        if(xpos[i] < xmin)
            xmin = xpos[i];
        if(ypos[i] > ymax)
            ymax = ypos[i];
        if(ypos[i] < ymin)
            ymin = ypos[i];
    }

    int xy = (xmax-xmin)*(ymax-ymin);

    printf("%d", xy);

    free(xpos);
    free(ypos);

    return 0;

}