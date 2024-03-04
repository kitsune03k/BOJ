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
}Vim;

void VimInit(Vim* V){
    V->head = (Char*)calloc(sizeof(Char), 1); // dmy node;
    V->tail = (Char*)calloc(sizeof(Char), 1); // dmy node;

    V->head->prev = NULL;
    V->head->next = V->tail;
    V->tail->prev = V->head;
    V->tail->next = NULL;

    V->cur = V->head;
    V->numofdata = 0;
}

void fxL(Vim* V) // 커서 <<
{
    if(V->cur->prev != NULL)
        V->cur = V->cur->prev;
}

void fxD(Vim* V) // 커서 >>
{
    if(V->cur->next != V->tail)
        V->cur = V->cur->next;
}

void fxP(Vim* V, char c) // 입력
{
    if(V->numofdata < 600000) {
        Char* newChar = (Char*)calloc(sizeof(Char), 1);
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

void fxB(Vim* V) // bksp
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

void printall(Vim *V)
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
    Vim* V = (Vim*)calloc(sizeof(Vim), 1);
    VimInit(V);

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
    printall(V);

    free(V);

    return 0;

}