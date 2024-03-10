#include <stdio.h>

int levels[512];

int mypow(int x, int n) { // x의 n승
    if(n == 0) {
        return 1;
    }

    int ret = 1;

    for(int i = 0; i < n; i++) {
        ret *= x;
    }

    return ret;
}

void avicii(int length, int lv, int start, int end) { // idx 다룸
    if(lv < 1) {
        return;
    }
    else {
        int cnt = length / 2;
        printf("[%d] = %d\n", cnt+start, lv);

        avicii(length / 2, lv - 1, start, start + cnt - 1);
        levels[start + cnt] = lv;
        avicii(length / 2, lv - 1, start + cnt + 1, end);
    }
}

int main(void) {
    int k = 4;
    int len = mypow(2, k) - 1;

    avicii(len, k, 0, len - 1); // idx 다뤄야하기에 end = len-1

    for(int i = 0; i < len; i++) {
        printf("%d ", levels[i]);
    }
}