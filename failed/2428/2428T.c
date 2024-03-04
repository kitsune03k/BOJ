#include <stdio.h>
#include <stdbool.h>

#define ULL unsigned long long

bool filter(int i1, int i2){
    ULL u1, u2; // u1 < u2

    if(i1 < i2){
        u1 = (ULL)i1;
        u2 = (ULL)i2;
    }
    else{ // i1 >= i2
        u1 = (ULL)i2;
        u2 = (ULL)i1;
    }

    if(10 * u1 + u2 < 10 * u2)
        return false;
    else
        return true;
}


int main(void){
    int N;
    scanf("%d", &N);
    getchar();

    int files[N];
    for(int i=0; i<N; i++){
        scanf("%d", &files[i]);
        getchar();
    }

    int ans = 0; // 검사해야하는 갯수
    for(int i=0; i<N-1; i++)
        for(int j=i+1; j<N; j++)
            if(filter(files[i], files[j]))
                ans++;

    printf("%d", ans);


    return 0;

}