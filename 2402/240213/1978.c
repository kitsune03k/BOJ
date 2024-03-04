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
    int N;
    scanf("%d", &N);
    getchar();

    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    int pcount = 0;
    for(int i=0; i<N; i++){
        if(isprime(arr[i]))
            pcount++;
    }

    printf("%d", pcount);

    return 0;

}