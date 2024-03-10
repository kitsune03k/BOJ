#include <stdio.h>
#include <stdlib.h>

typedef struct _B{
    int BName;
    int i;
    struct _B * lB;
    struct _B * rB;
} B;

B* makeBFirst(int BN, int i){
    B * newB = (B *)malloc(sizeof(B));
    newB->BName = BN;
    newB->i = i;

    return newB;
}

B* makeBNext(int BN, int i, B* prev){
    B * newB = (B *)malloc(sizeof(B));
    newB->BName = BN;
    newB->i = i;

    prev->rB = newB;
    newB->lB = prev;

    return newB;
}

B* makeBLast(int BN, int i, B* prev, B* first){
    B * newB = (B *)malloc(sizeof(B));
    newB->BName = BN;
    newB->i = i;

    prev->rB = newB;
    newB->lB = prev;

    newB->rB = first;
    first->lB = newB;

    return newB;
}

B* destroyB(B* cur){
    B* ret = cur;

    int time = cur->i;
    int k;

    B* tmpcl = cur->lB;
    B* tmpcr = cur->rB;

    // 1. 원형 연결 리스트 다시 연결
    cur->lB->rB = tmpcr;
    cur->rB->lB = tmpcl;

    // 2. cur 이동
    if(cur->i > 0){
        for(k=0; k<time; k++) {
            ret = ret->rB;
        }
    }
    else{
        for(k=0; k>time; k--) {
            ret = ret->lB;
        }
    }

    return ret;
}