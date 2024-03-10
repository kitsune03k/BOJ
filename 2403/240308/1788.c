#include <stdio.h>

unsigned long long fibo(int n) {
    unsigned long long arr[n + 1];
    arr[0] = 0;
    arr[1] = arr[2] = 1;

    for(int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];

        if(arr[i] > 1000000000) {
            arr[i] %= 1000000000;
        }
    }

    return arr[n]; // % 1000000000;
}

int main(void) {
    int tmp;
    scanf("%d", &tmp);
    getchar();

    int n;
    int isneg;

    if(tmp == 0) {
        isneg = 0;
        n = tmp;
    }
    else {
        if(tmp > 0) {
            isneg = 1;
            n = tmp;
        }
        else {
            if((tmp * -1) % 2 == 1) {
                isneg = 1;
            }
            else {
                isneg = -1;
            }

            n = tmp * -1;
        }
    }

    unsigned long long ans = fibo(n);
    printf("%d\n%llu", isneg, ans);


}