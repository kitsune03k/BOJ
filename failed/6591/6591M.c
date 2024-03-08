#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

uint pascal(uint n, uint tmpr) {
    int **arr = (int **) malloc(sizeof(int *) * n * (n + 1));
    for(int i = 0; i <= n; i++) {
        arr[i] = (int *) malloc(sizeof(int) * (n + 1));
    }
    uint r = tmpr < n - tmpr ? tmpr : n - tmpr; // r은 더 작은 수;

    for(int i = 0; i <= n; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }

    for(int i = 2; i < n; i++) {
        for(int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            //printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }

    uint ret = 0;
    for(uint i = r - 1; i < n; i++) {
        //printf("(%d %d) = %d\n", i, r-1, arr[i][r-1]);
        ret += arr[i][r - 1];
    }

    for(int i = 0; i <= n; i++) {
        free(arr[i]);
    }
    free(arr);

    return ret;
}


int main(void) {
    uint ans[100];

    uint i, n, r;

    for(i = 0;; i++) {
        scanf("%u %u", &n, &r);
        getchar();

        if(n == 0 && r == 0) {
            break;
        }

        ans[i] = pascal(n, r);
    }

    for(uint j = 0; j < i; j++) {
        printf("%u\n", ans[j]);
    }
}

