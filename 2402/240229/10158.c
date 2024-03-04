#include <stdio.h>

typedef long long ll;

int main(void){
    ll limx, limy, antx, anty, t;

    scanf("%lld %lld", &limx, &limy);
    getchar();
    scanf("%lld %lld", &antx, &anty);
    getchar();
    scanf("%lld", &t);
    getchar();

    ll addx = t % (2 * limx);
    ll addy = t % (2 * limy);

    antx += addx;
    anty += addy;

    if(antx > limx){
        if(antx > 2 * limx)
            antx -= 2 * limx;
        else
            antx = 2 * limx - antx;
    }

    if(anty > limy){
        if(anty > 2 * limy)
            anty -= 2 * limy;
        else
            anty = 2 * limy - anty;
    }

    printf("%lld %lld\n", antx, anty);
}