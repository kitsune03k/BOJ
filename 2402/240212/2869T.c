#include <stdio.h>

int main(void)
{
    int A, B, V;

    scanf("%d %d %d", &A, &B, &V);

    int day = 0;
    int height = 0;

    for(int i=0; i<1000000000; i++) {
        day++;
        height += A;
        if(height >= V)
            break;
        else
            height -= B;
    }

    printf("%d", day);

}