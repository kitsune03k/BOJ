#include <stdio.h>
#define ULL unsigned long long

int main(void)
{
    int N;
    scanf("%d", &N);
    getchar();

    int ans = 1;
    for(int i=1; i<=N; i++){
        ans *= i;

        if(ans>100){
            ans%=100;
        }
        ans%=10;

        printf("[%d] : %d\n", i, ans);
    }

    printf("%d", ans%10);

    return 0;
}