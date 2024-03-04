#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char txt[600000]; // [0]~[599999]
    int cur; // 0~600000
}Vim;


void fxL(Vim* V) // 커서 <<
{
    if(V->cur > 0)
        V->cur--;
}

void fxD(Vim* V) // 커서 >>
{
    if(V->cur < strlen(V->txt))
        V->cur++;
}

void fxP(Vim* V, char c) // 입력
{
    if(V->cur < 600000) {
        for(int i = 599999; i > V->cur; i--) {
            V->txt[i] = V->txt[i - 1];
        }
        V->txt[V->cur] = c;

        fxD(V);
    }
}

void fxB(Vim* V) // bksp
{
    if(V->cur > 0) {
        for(int i = V->cur-1; i < 599999; i++) {
            V->txt[i] = V->txt[i + 1];
        }
        V->txt[599999] = '\0';

        fxL(V);
    }
}


int main(void)
{
    Vim* V = (Vim*)calloc(sizeof(Vim), 1);

    char rt[100000] = {0,};
    scanf("%s", rt);
    getchar();

    for(int i=0; i<strlen(rt); i++){
        fxP(V, rt[i]);
    }

    int M;
    scanf("%d", &M);
    getchar();

    char func;
    for(int i=0; i<M; i++){
        scanf("%c", &func);
        getchar();
        if(func == 'P'){
            char c;
            scanf("%c", &c);
            getchar();
            fxP(V, c);
        }
        else if(func == 'L'){
            fxL(V);
        }
        else if(func == 'D'){
            fxD(V);
        }
        else if(func == 'B'){
            fxB(V);
        }
        else{ // 입력에러
            ;
        }

    }
    printf("%s", V->txt);
    free(V);

    return 0;

}