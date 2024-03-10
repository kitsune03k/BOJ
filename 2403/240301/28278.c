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
        for(int i=0; i<S->numofdata; i++){
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
    Stackinit(S, 100000000);

    int n; // query 갯수
    scanf("%d", &n);
    getchar();

    int ans[n];
    int nidx = 0;

    int buf;
    for(int i=0; i<n; i++){
        scanf("%d", &buf);

        switch(buf){
            case 1:{
                int topush;
                scanf("%d", &topush);
                getchar();

                SPush(S, topush);
                break;
            }
            case 2: {
                ans[nidx++] = SPop(S);
                break;
            }
            case 3: {
                ans[nidx++] = SCount(S);
                break;
            }
            case 4: {
                ans[nidx++] = SIsEmpty(S);
                break;
            }
            case 5: {
                ans[nidx++] = SPeek(S);
                break;
            }

            default:
                break;
        }

        //SShow(S);
    }

    for(int i=0; i<nidx; i++){
        int prt = ans[i];

        printf("%d\n", prt);
    }

}