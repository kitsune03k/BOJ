#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


long double calcdis(long double cntx, long double cnty, int px, int py) {

}

bool issquare(long long arr[]) {
    long double cntx, cnty;
    
    for(int i=0; i<8; i++){

    }

    for(int i = 0; i < 8; i++) {
        if(i % 2 == 0) {
            cntx += (long double) arr[i] / 4.0;
        }
        else {
            cnty += (long double) arr[i] / 4.0;
        }
    }

    long double dis[4];

    for(int i = 0; i < 4; i++) {
        dis[i] = calcdis(cntx, cnty, arr[2 * i], arr[2 * i + 1]);
        printf("%Lf\n", dis[i]);
    }

    // filter 1. 중점으로부터의 거리가 모두 같냐?
    if(
            (float) dis[0] == (float) dis[1] &&
            (float) dis[1] == (float) dis[2] &&
            (float) dis[2] == (float) dis[3] &&
            (float) dis[3] == (float) dis[0]
            ) {return true; // 내마음대로 정밀도 줄임, long double 연산시 부동소수점 오류때문에..
    }
    else {
        return false;
    }

}

int main(void) {
    int t;
    scanf("%d", &t);
    getchar();

    bool ans[t];

    long long arr[8];
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < 8; j++) {
            scanf("%lld", &arr[j]);
            getchar();
        }

        printf("%d", issquare(arr));
    }


}