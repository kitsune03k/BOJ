#include <stdio.h>

int main(void)
{
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);

    int ret;

    if(V < A){
        printf("error");
    }
    else if(V == A){
        ret = 1;
    }
    else{
        ret = (V-A-1)/(A-B) + 2;
    }

    printf("%d", ret);

    return 0;

}