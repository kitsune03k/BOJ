#include <stdio.h>

typedef unsigned long long ull;

int main(void) {
    ull ans[100];

    ull i, n, r;

    for(i = 0;; i++) {
        ull ret = 1;
        scanf("%llu %llu", &n, &r);
        getchar();

        if(n == 0 && r == 0) {
            break;
        }

        if(n == 1) {
            ans[i] = ret;
            continue;
        }
        if(n == r){
            ans[i] = ret;
            continue;
        }
        else {
            for(int x = r; x < n; x++) {
                ret *= x + 1;
                ret /= x + 1 - r;
            }

            ans[i] = ret;
        }
    }

    for(ull j = 0; j < i; j++) {
        printf("%llu\n", ans[j]);
    }
}