#include <stdio.h>
#include <stdlib.h>

int cmp(const void* x1, const void* x2){
    int i1 = *(int*)x1;
    int i2 = *(int*)x2;

    if(i1 == i2){
        return 0;
    }
    else{
        if(i1 < i2)
            return 1;
        else
            return -1;
    }
}

int main(void){
    unsigned int n, x;
    scanf("%d %d", &n, &x);
    getchar();

    unsigned int buf[n+1];
    buf[0] = 0;

    unsigned long window[n+1];
    for(int i=0; i<x; i++){
        window[i] = 0;
    }

    for(int i=1; i<=n; i++){
        scanf("%u", &buf[i]);
        getchar();

        buf[i] += buf[i-1];

        if(i >= x){
            window[i] = buf[i] - buf[i-x];
        }
    }

    qsort(window, n+1, sizeof(unsigned long), cmp);

    unsigned long max = window[0];
    unsigned long maxcount = 0;
    for(int i=0; i<=n; i++){
        if(window[i] == max)
            maxcount++;
    }

    if(max == 0){
        printf("SAD");
    }
    else{
        printf("%lu\n", max);
        printf("%lu", maxcount);
    }

}