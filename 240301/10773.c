#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef int Data;

typedef struct{
    Data * arr;
    int sz;
    int numofdata;
} Stack;

void Stackinit(Stack * S, int stsz){
    S->arr = (Data*)malloc(sizeof(Data) * stsz+1);
    memset(S->arr, 0, sizeof(Data) * stsz+1);
    S->sz = stsz;
    S->numofdata = 0;
}

int SCount(Stack * S){
    return S->numofdata;
}

bool SIsEmpty(Stack * S){
    if(SCount(S) == 0)
        return true;
    else
        return false;
}

Data SPeek(Stack * S){
    if(SIsEmpty(S) == false){
        return S->arr[S->numofdata];
    }
    else{
        //printf("nothing to peek!\n");
        return -1;
    }
}

Data SPop(Stack * S){
    if(SIsEmpty(S) == false){
        Data ret = SPeek(S);
        S->numofdata--;

        return ret;
    }
    else{
        //printf("nothing to pop!\n");
        return -1;
    }
}

bool SPush(Stack * S, Data D){
    if(SCount(S) <= S->sz){
        S->numofdata++;
        S->arr[S->numofdata] = D;
        return true;
    }
    else{
        //printf("memory exceed limit!\n");
        return false;
    }
}

// for debug
void SShow(Stack* S){
    if(S->numofdata > 0){
        for(int i=1; i<=S->numofdata; i++){
            printf("%d ", S->arr[i]);
        }
        printf("\n");
    }
    else{
        //printf("nothing to show!\n");
    }
}

int main(void){
    Stack * S = (Stack *)malloc(sizeof(Stack));
    Stackinit(S, 123456);

    int k; // query 갯수
    scanf("%d", &k);
    getchar();

    int buf;
    for(int i=0; i<k; i++){
        scanf("%d", &buf);
        getchar();

        if(buf == 0){
            SPop(S);
        }
        else{
            SPush(S, buf);
        }
    }

    int ans = 0;
    int anslen = SCount(S);

    for(int i=1; i<=anslen; i++) {
        int ret = SPop(S);
        ans += ret;
    }

    printf("%d", ans);

}