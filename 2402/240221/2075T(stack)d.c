#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PN printf("\n")

typedef int Data;

typedef struct{
    Data arr[1500];
    int head; // = num of data
} Stack;

void sInit(Stack* S)
{
    S->head = -1;
}

bool sEmpty(Stack* S)
{
    if(S->head == -1)
        return true;
    else
        return false;
}

void sPush(Stack* S, Data data)
{
    S->head++;
    S->arr[S->head] = data;
}

Data sPeek(Stack* S)
{
    if(!sEmpty(S)){
        Data ret = S->arr[S->head];
        return ret;
    }
    else{
        return 0;
    }
}

Data sPop(Stack* S)
{
    if(!sEmpty(S)) {
        Data ret = sPeek(S);
        S->head--;
        return ret;
    }
    else{
        return 0;
    }
}

void show(Stack* S)
{
    if(!sEmpty(S)){
        for(int i = 0; i <= S->head; i++) {
            printf("%d ", S->arr[i]);
        }
        printf("| head : %d[%d]\n", S->arr[S->head], S->head);
    }
    else{
        printf("stack empty!\n");
    }

}

int main(void)
{
    int N;
    scanf("%d", &N);
    getchar();

    Stack starr[N];
    for(int i=0; i<N; i++){
        sInit(&starr[i]);
    }

    int tmp;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &tmp);
            sPush(&starr[j], tmp);
        }
    }

    Data smax;
    for(int k = 0; k < N; k++) {
        smax = -1;

        int peekret, peekidx;
        for(int i = 0; i < N; i++) {
            peekret = sPeek(&starr[i]);

            if(peekret > smax){
                smax = peekret;
                peekidx = i;
            }
        } // 최대값 각 스택 돌아다니면서 찾음

        sPop(&starr[peekidx]);

        for(int j=0; j<N; j++){
            show(&starr[j]);
        }
        PN;
    }

    printf("%d", smax);

    return 0;

}