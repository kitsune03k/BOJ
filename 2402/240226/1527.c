#include <stdio.h>
#include <stdbool.h>

#define UI unsigned int

bool check47(UI x) {
    if(x == 4 || x == 7)
        return true;
    else
        return false;
}

bool check(UI x) {
    bool ret = true;

    UI tmp = x;
    while(tmp > 0) {
        if(tmp % 10 == 4 || tmp % 10 == 7)
            tmp /= 10;
        else {
            ret = false;
            break;
        }
    }

    return ret;
}

int main(void) {
    UI A, B;
    scanf("%d %d", &A, &B);
    getchar();

    UI ans = 0;

    for(UI i = A; i <= B; i++)
        if(check(i))
            ans++;

    printf("%d", ans);


    return 0;

}