#include <stdio.h>

typedef unsigned long long ull;

ull arr[1000001];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    ull tmp;
    ull prev = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%llu", &tmp);
        getchar();
        arr[i] = tmp % 3 + prev;
        prev = arr[i];
    }

    ull ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if((arr[j] - arr[i - 1]) % m == 0) {
                ans++;
            }
        }
    }

    printf("%llu", ans);

}