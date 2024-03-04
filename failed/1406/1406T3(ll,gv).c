#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Char{
    char c;
    struct _Char * prev;
    struct _Char * next;
} Char;

typedef struct{
    Char* head;
    Char* tail;
    Char* cur;
    int numofdata;
} Vim;

Vim myVim;
Vim* V = &myVim;


void VimInit(void)
{
    V->head = (Char*)malloc(sizeof(Char)); // dmy node;
    V->tail = (Char*)malloc(sizeof(Char)); // dmy node;

    V->head->prev = NULL;
    V->head->next = V->tail;
    V->tail->prev = V->head;
    V->tail->next = NULL;

    V->cur = V->head;
    V->numofdata = 0;
}

void fxL() // 커서 <<
{
    if(V->cur->prev != NULL)
        V->cur = V->cur->prev;
}

void fxD() // 커서 >>
{
    if(V->cur->next != V->tail)
        V->cur = V->cur->next;
}

void fxP(char c) // 입력
{
    if(V->numofdata < 600000) {
        Char* newChar = (Char*)malloc(sizeof(Char));
        newChar->c = c;

        V->cur->next->prev = newChar;
        newChar->next = V->cur->next;
        V->cur->next = newChar;
        newChar->prev = V->cur;

        V->cur = newChar;
        V->numofdata++;
    }
    else{
        printf("memory over!!\n");
    }
}

void fxB() // bksp
{
    if(V->cur->prev != NULL){
        Char* bkup = V->cur->prev;

        V->cur->prev->next = V->cur->next;
        V->cur->next->prev = V->cur->prev;

        free(V->cur);
        V->cur = bkup;

        V->numofdata--;
    }
}

void printall()
{
    Char* bkup = V->cur;

    V->cur = V->head->next;

    for(int i=0; i<V->numofdata; i++){
        printf("%c", V->cur->c);
        V->cur = V->cur->next;
    }

    V->cur = bkup;
}



int main(void)
{
    VimInit();
    char rt[100000] = {0,};
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

    }
    printall();

    return 0;

}