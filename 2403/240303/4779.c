#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

void cantor(int level, int start, int end, char arr[]) {
    if(level == 0) {
        return;
    }

    int gap = mypow(3, level - 1);
    int sep1 = start;
    int sep2 = sep1 + gap;
    int sep3 = sep2 + gap;
    int sep4 = end;

    for(int i = sep2; i < sep3; i++) {
        arr[i] = ' ';
    }
    cantor(level - 1, sep1, sep2, arr);
    cantor(level - 1, sep3, sep4, arr);

}

int main(void) {
    int n, len;
    char buf[3];
    char* arr;
    while(true) {
        memset(buf, 0, 3);
        gets(buf);

        if(strlen(buf) == 0)
            break;

        n = atoi(buf);
        len = mypow(3, n);
        arr = (char *)malloc(sizeof(char) * len);
        memset(arr, '-', len);
        cantor(n, 0, len, arr);

        for(int i = 0; i < len; i++) {
            printf("%c", arr[i]);
        }
        printf("\n");
        free(arr);
    }
}