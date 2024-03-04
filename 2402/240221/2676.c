#include <stdio.h>
#include <stdlib.h>

#define ULL unsigned long long


// n이 짝수
ULL rascaleven(int n, int m)
{
    ULL ret;

    ULL* arr = (ULL*)malloc(sizeof(ULL)*(n+1));
    arr[0] = 1;
    arr[n] = 1;

    ULL toadd = n-1;
    for(int i=1; i<=n/2; i++){
        arr[i] = arr[i-1]+toadd;
        arr[n-i] = arr[i];
        toadd -= 2;
    }

    ret = arr[m];
    free(arr);

    return ret;
}

// n이 홀수
ULL rascalodd(int n, int m)
{
    ULL ret;

    ULL* arr = (ULL*)malloc(sizeof(ULL)*(n+1));
    arr[0] = 1;
    arr[n] = 1;

    ULL toadd = n-1;
    for(int i=1; i<=n/2; i++){
        arr[i] = arr[i-1]+toadd;
        arr[n-i] = arr[i];
        toadd -= 2;
    }

    ret = arr[m];
    free(arr);

    return ret;
}


int main(void)
{
    int T;
    scanf("%d", &T);
    getchar();

    ULL* answer = (ULL*)malloc(sizeof(ULL)*T);

    int N, M;
    for(int i=0; i<T; i++){
        scanf("%d %d", &N, &M);
        if(N % 2 == 0)
            answer[i] = rascaleven(N, M);
        else
            answer[i] = rascalodd(N, M);
    }

    for(int i=0; i<T; i++){
        printf("%llu\n", answer[i]);
    }

    free(answer);

    return 0;

}