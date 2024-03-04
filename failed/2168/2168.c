#include <stdio.h>

#define LD long double
#define ULL unsigned long long
int main(void){
    int row, col;
    scanf("%d %d", &row, &col);
    getchar();

    LD d = (LD)row/(LD)col;

    ULL ans = 0;
    for(int i=0; i<col; i++){
        LD dcur = d*i;
        int icur = (int)dcur; // 소수점 날리고 다시 double로
        LD dnext = d*(i+(LD)1.0);
        int inext = (int)dnext;

        //printf("dcur = %Lf | icur = %llu || dnext = %Lf | inext = %llu\n", dcur, icur, dnext, inext);

        if(dnext - (LD)inext == 0){
            ans += (inext - icur);
        }
        else{
            ans += (inext - icur + 1);
        }
    }

    printf("%lld", ans);
}