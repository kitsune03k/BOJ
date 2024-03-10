#include <stdio.h>

typedef unsigned long long ull;

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    ull arr[n+1][n+1];
    arr[0][n] = 0;

    ull arrarr[m+1][5]; // row당 x1 y1 x2 y2
    ull ans[m+1];

    ull prev = 0;
    ull tmp;
    for(int i=1; i<=n; i++){
        arr[i][0] = arr[i-1][n];
        for(int j=1; j<=n; j++){
            scanf("%llu", &tmp);
            arr[i][j] = tmp + prev;
            prev = arr[i][j];
        }
    }
    getchar();

    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++){
            scanf("%llu", &arrarr[i][j]);
        }
        getchar();

        ull sum = 0;
        for(ull row = arrarr[i][1]; row <= arrarr[i][3]; row++){
            sum += (arr[row][arrarr[i][4]] - arr[row][arrarr[i][2]-1]);
        }

        ans[i] = sum;
    }

    for(int i=1; i<=m; i++){
        printf("%llu\n", ans[i]);
    }


    return 0;

}