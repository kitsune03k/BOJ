#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    getchar();

    char room[N][N];

    for(int i=0; i<N; i++){
        scanf("%s", room[i]);
    }
    getchar();

    int rplace = 0, rcount = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=N; j++){
            if(j != N){
                if(room[i][j] == '.')
                    rcount++;
                else if(room[i][j] == 'X'){
                    if(rcount >= 2)
                        rplace++;
                    rcount = 0;
                }
            }
            else{
                if(rcount >= 2)
                    rplace++;
            }
        }
        rcount = 0;
    }

    int cplace = 0, ccount = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<=N; j++) {
            if(j != N){
                if(room[j][i] == '.')
                    ccount++;
                else if(room[j][i] == 'X') {
                    if(ccount >= 2)
                        cplace++;
                    ccount = 0;
                }
            }
            else{
                if(ccount >= 2)
                    cplace++;
            }
        }
        ccount = 0;
    }

    printf("%d %d", rplace, cplace);

    return 0;
}