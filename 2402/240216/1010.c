#include <stdio.h>

unsigned long long npr(int n, int r)
{
    unsigned long long ret = 1;

    int nr = n-r;

    for(int i=nr+1; i<=n; i++){
        ret *= i;
    }

    return ret;
}

unsigned long long ncr(int n, int r)
{
    unsigned long long ret = 1;

    int nr = n-r;
    int div1, div2; // div1 < div2, div1 + div2 = n

    if(nr < r){
        div1 = nr;
        div2 = r;
    }
    else{ // nr >= r
        div1 = r;
        div2 = nr;
    }

    unsigned long long k = 1, kref = 1;

    for(int i = div2+1; i<=n; i++){
        ret *= i;
        k *= kref++;
    }

    return ret/k;
}

int main(void) {
    int T;
    scanf("%d", &T);
    getchar();

    int Tarr[T][2];

    for(int i = 0; i < T; i++) {
        scanf("%d %d", &Tarr[i][0], &Tarr[i][1]);
    }
    getchar();

    for(int i=0; i<T; i++){
        printf("%llu\n", ncr(Tarr[i][1], Tarr[i][0]));
    }

    return 0;
}