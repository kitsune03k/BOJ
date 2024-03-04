#include <stdio.h>
#include <stdbool.h>


bool check(int x){
    int del = 1;
    while(1){
        x -= del++;
        if(x<=0)
            break;
    }
    if(x == 0)
        return true;
    else
        return false;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int rc = 2, a = 1, b;
    int p1, p2;

    for(int i=1; i<=n; i++){
        b = rc - a;

        if(rc % 2 == 0) {
            p1 = a;
            p2 = b;
        }
        else {
            p1 = b;
            p2 = a;
        }

        a--;

        if(check(i)){
            rc++;
            a = rc-1;
        }
    }

    printf("%d/%d", p1, p2);
}