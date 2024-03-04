#include <stdio.h>

typedef struct {
    int row;
    int col;
} Pos;

int calcdis(int pos, int len){
    int ret = len/2 - pos % len;

    if(ret < 0)
        ret *= -1;

    return ret;
}

int main(void) {
    int N, R1, C1, R2, C2;
    scanf("%d %d %d %d %d", &N, &R1, &C1, &R2, &C2);
    getchar();

    int len = 2 * N - 1;
    int dis;

    for(int i = R1; i <= R2; i++) { // row
        for(int j = C1; j <= C2; j++) {
            dis = calcdis(i, len) + calcdis(j, len);
            if(dis >= N)
                printf(".");
            else
                printf("%c", dis%26+'a');
        }
        printf("\n");
    }

    return 0;

}