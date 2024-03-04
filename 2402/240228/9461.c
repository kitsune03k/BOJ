#include <stdio.h>

#define ULL unsigned long long
ULL arr[101];
int known;

ULL padoban(int n){
    if(n > known){
        for(int i = known+1; i <= n; i++){
            arr[i] = arr[i-1] + arr[i-5]; // 필요할때만 갱신
        }
    }

    return arr[n];
}


int main(void){
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;

    known = 5;

    int T;
    scanf("%d", &T);
    getchar();

    ULL ans[T];
    int tmp;

    for(int i=0; i<T; i++){
        scanf("%d", &tmp);
        getchar();

        ans[i] = padoban(tmp);
    }

    for(int i=0; i<T; i++){
        printf("%llu\n", ans[i]);
    }

    return 0;

}