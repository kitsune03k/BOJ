#include <stdio.h>

char filter(int dec) {
    int minabc = 0x40, maxabc = 0x5f;
    int minds = 0x10, maxds = 0x1f;

    if(dec > 0x30) {
        if(dec >= minabc && dec <= maxabc) {
            return '-';
        }
    }
    else {
        if(dec >= minds && dec <= maxds) {
            return '.';
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    getchar();

    char ans[N];
    int hex;

    for(int i = 0; i < N; i++) {
        scanf("%x", &hex);
        getchar();

        ans[i] = filter(hex);
    }

    printf("%s", ans);


    return 0;

}