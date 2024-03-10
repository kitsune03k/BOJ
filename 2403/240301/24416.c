#include <stdio.h>

int fibo1 (int n) {
    if(n == 1 || n == 2)
        return 1;
    else{
        return (fibo1(n-1) + fibo1(n-2));
    }
}


int fibo2 (int n) {
    int opcount = 0;
    int arr[n+1];
    arr[1] = arr[2] = 1;

    for(int i = 3; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
        opcount++;
    }

    return opcount;
}

int main(void){
    int n;
    scanf("%d", &n);
    getchar();

    printf("%d %d", fibo1(n), fibo2(n));

    return 0;
}