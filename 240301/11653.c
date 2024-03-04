#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    getchar();

    int x = n;
    int div = 2;

    while(x > 0) {
        if(x % div == 0) {
            x /= div;
            printf("%d\n", div);
        }
        else {
            div++;
        }

        if(div > n)
            break;
    }

    return 0;
}