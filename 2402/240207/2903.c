#include <stdio.h>

int nsq(int x, int t)
{
    int ret = 1;
    for(int i=0; i<t; i++){
        ret *= x;
    }

    return ret;
}

int main(void)
{
    int t;
    scanf("%d", &t);

    printf("%d", nsq((nsq(2, t) + 1), 2));
}