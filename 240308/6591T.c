#include <stdio.h>

typedef unsigned long long ull;

ull pascal(int n, int r){
    //printf("%d C %d\n", n, r);
    if(r == 0 || r == n)
        return 1;
    else{
        return pascal(n-1, r-1) + pascal(n-1, r);
    }
}


int main(void){
    ull ans[100];

    ull i, n, r;

    for(i=0; ; i++){
        scanf("%llu %llu", &n, &r);
        getchar();

        if(n == 0 && r == 0)
            break;

        ans[i] = pascal(n,r);
    }

    for(int j=0; j<i; j++){
        printf("%llu\n", ans[j]);
    }
}

