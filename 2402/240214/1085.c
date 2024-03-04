#include <stdio.h>

int main(void)
{
    int x, y, w, h; 
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int d[4]; // h(left) j(down) k(up) l(right);

    d[0] = x;
    d[1] = y;
    d[2] = h-y;
    d[3] = w-x;

    int min = 1234;

    for(int i=0; i<4; i++){
        if(d[i]<=min){
            min = d[i];
        }
    }

    printf("%d", min);

    return 0;
}
