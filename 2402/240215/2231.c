#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// x의 n승
int mypow(int x, int n)
{
    int ret = 1;

    if(n == 0)
        return 1;
    else {
        for(int i = 0; i < n; i++) {
            ret *= x;
        }
    }

    return ret;
}


int main(void)
{
    char N[10];
    scanf("%s", N);

    int NN = atoi(N), length = strlen(N);
    int cases = mypow(10,length);

    printf("length %d\n", length);

    int sum, answer = 0;

    int i;
    for(i=0; i<cases; i++){
        printf("case %d - ", i);
        sum = 0;

        // 1. 숫자 자체를 더함
        sum += i;

        // 2. 각 자리별 숫자를 더함
        int tmp = i, toadd;
        int todiv = mypow(10,length-1);
        for(int j=0; j<length; j++){
            printf("%d의 자리 : ", todiv);
            toadd = tmp/todiv;
            printf("%d ", toadd);
            sum += toadd;
            tmp -= toadd*todiv;
            todiv /= 10;
        }

        printf(" || %d\n", sum);

        if(sum == NN) {
            answer = i;
            break;
        }
    }

    printf("%d", answer);

    return 0;

}