#include <stdio.h>
#include <stdbool.h>

bool isprime(int x)
{
    if(x == 1)
        return false;

    for(int i=2; i<x; i++){
        if(x%i == 0)
            return false;
    }

    return true;
}

int main(void)
{
    int M, N; // 구간 [M,N]

    scanf("%d %d", &M, &N);

    int psum = 0, pcount = 0, pmin = 0;

    for(int i=M; i<=N; i++){
        if(isprime(i)){
            if(pcount == 0)
                pmin = i;

            psum+=i;
            pcount++;
        }
    }

    if(pcount == 0){
        printf("%d", -1);
    }
    else{
        printf("%d\n%d", psum, pmin);
    }

    return 0;
}