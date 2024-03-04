#include <stdio.h>
#include <stdlib.h>

unsigned long long npr(int n, int r)
{
    unsigned long long ret = 1;

    int nr = n-r;

    for(int i=nr+1; i<=n; i++){
        ret *= i;
    }

    return ret;
}

int main(void)
{
    int cases = npr(10,10);
    for(int i=1; i<=10; i++){

    }

}