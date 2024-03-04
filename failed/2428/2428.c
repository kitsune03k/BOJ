#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ULL unsigned long long
#define UI unsigned int
#define PN printf("\n")

int compare(const void* x, const void* y){
    ULL ux = *(ULL*)x, uy = *(ULL*)y;
    if(ux == uy)
        return 0;
    else{
        if(ux > uy)
            return -1;
        else
            return 1;
    }
}

bool filter(int i1, int i2){
    ULL u1, u2; // u1 < u2

    if(i1 < i2){
        u1 = (ULL)i1;
        u2 = (ULL)i2;
    }
    else{ // i1 >= i2
        u1 = (ULL)i2;
        u2 = (ULL)i1;
    }

    if(10 * u1 + u2 < 10 * u2)
        return false;
    else
        return true;
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

int main(void){
    int N;
    scanf("%d", &N);
    getchar();

    ULL files[N];
    ULL tmp;
    for(int i=0; i<N; i++){
        scanf("%llu", &tmp);
        files[i] = (ULL)tmp*(ULL)10;
        getchar();
    }

    qsort(files, N, sizeof(ULL), compare); // 내림차순 정렬


    ULL ans = 0; // 검사해야하는 갯수
    ULL sz = 1000000001, szstd;
    int curszst, curszed;
    int stdszst, stdszed;
    int i, j;

    for(i=0; i<N; i++){
        if(sz != files[i]){
            sz = files[i];
            curszst = i;
            stdszst = i;
        }
        i += 1;

        while(files[i] >= sz)
            i++;
        i -= 1;

        curszed = i;

        int curszlen = curszed - curszst + 1;

        szstd = sz / 10 * 9;

        for(stdszed = i;  ; stdszed++) {
            if(files[stdszed] < szstd){
                stdszed -= 1;
                break;
            }

        }

        int stdszlen = stdszed - stdszst + 1;

        ULL tmp2 = curszlen * ncr(stdszlen, 2);
        ans += tmp2;

        printf("current size length : %d, standard size length : %d\n", curszlen, stdszlen);
        printf("[%d](%llu) ~ [%d](%llu) -> %llucmps\n", stdszst, files[stdszst], stdszed, files[stdszed], tmp2);
    }



    printf("%d", ans);


    return 0;

}