#include <string.h>
#include <stdio.h>

typedef struct{
    char txt[600000]; // [0]~[599999]
    int cur;
    int numofdata; // 0~600000;
}Vim;

Vim myVim;
Vim* V = &myVim;

void fxL() // 커서 <<
{
    if(V->cur > 0)
        V->cur--;
}

void fxD() // 커서 >>
{
    if(V->cur < V->numofdata)
        V->cur++;
}

void fxP(char c) // 입력
{
    if(V->cur <= V->numofdata) {
        if(V->cur != V->numofdata) { // 배열 중간에 입력시
            for(int i = V->numofdata; i > V->cur; i--) {
                V->txt[i] = V->txt[i - 1];
            }
        }

        V->txt[V->cur] = c;
        V->numofdata++;
        fxD();
    }
    else{
        printf("memory over!\n");
    }
}

void fxB() // bksp
{
    if(V->cur > 0) {
        if(V->cur < V->numofdata) { // 배열 중간에에 실행시
            for(int i = V->cur-1; i < V->numofdata; i++) {
                V->txt[i] = V->txt[i + 1];
            }
        }
        else {
            V->txt[V->cur-1] = '\0';
        }
        V->numofdata--;
        fxL();
    }
}

void show(){
    printf("\"%s\", cur:%c[%d], nod:%d\n", V->txt, V->txt[V->cur], V->cur, V->numofdata);
}

char rt[100000];

int main(void)
{
    scanf("%s", rt);
    getchar();

    for(int i=0; i<strlen(rt); i++){
        fxP(rt[i]);
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
            fxP(c);
        }
        else if(func == 'L'){
            fxL();
        }
        else if(func == 'D'){
            fxD();
        }
        else if(func == 'B'){
            fxB();
        }
        else{ // 입력에러
            ;
        }
        //show(); // for debug
    }
    printf("%s", V->txt);

    return 0;

}