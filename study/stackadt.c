#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int Data;

typedef struct {
    Data *arr;
    int sz;
    int numofdata;
} Stack;

void StackInit(Stack *S, int stsz) {
    S->arr = (Data *) malloc(sizeof(Data) * stsz + 1);
    memset(S->arr, 0, sizeof(Data) * stsz + 1);
    S->sz = stsz;
    S->numofdata = 0;
}

void SReset(Stack *S){
    memset(S->arr, 0, sizeof(Data) * (S->sz + 1));
    S->numofdata = 0;
}

int SSize(Stack *S) {
    return S->numofdata;
}

bool SIsEmpty(Stack *S) {
    if(SSize(S) == 0) {
        return true;
    }
    else {
        return false;
    }
}

Data SPeek(Stack *S) {
    if(SIsEmpty(S) == false) {
        return S->arr[S->numofdata];
    }
    else {
        //printf("nothing to peek!\n");
        return -1;
    }
}

Data SPop(Stack *S) {
    if(SIsEmpty(S) == false) {
        Data ret = SPeek(S);
        S->numofdata--;

        return ret;
    }
    else {
        //printf("nothing to pop!\n");
        return -1;
    }
}

bool SPush(Stack *S, Data D) {
    if(SSize(S) <= S->sz) {
        S->numofdata++;
        S->arr[S->numofdata] = D;
        return true; // push 성공
    }
    else {
        //printf("memory exceed limit!\n");
        return false; // push 실패
    }
}

// for debug
void SShow(Stack *S) {
    if(S->numofdata > 0) {
        for(int i = 1; i <= S->numofdata; i++) {
            printf("%d ", S->arr[i]);
        }
        printf("\n");
    }
    else {
        printf("nothing to show!\n");
    }
}