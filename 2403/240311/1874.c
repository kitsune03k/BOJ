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

void SReset(Stack *S) {
    memset(S->arr, 0, sizeof(Data) * (S->sz + 1));
    S->numofdata = 0;
}

int SCount(Stack *S) {
    return S->numofdata;
}

bool SIsEmpty(Stack *S) {
    if(SCount(S) == 0) {
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
    if(SCount(S) <= S->sz) {
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


int main(void) {
    int n;
    scanf("%d", &n);
    getchar();

    Stack *S1 = (Stack *) malloc(sizeof(Stack));
    Stack *S2 = (Stack *) malloc(sizeof(Stack));
    StackInit(S1, 2*n);
    StackInit(S2, 2*n);

    int *arr = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        getchar();
        SPush(S1, n - i);
    }

    int arridx = 0;

    char* pp = (char*)malloc(sizeof(char) * 2 * n); // S2에 대한 push, pop연산 log 저장
    int ppidx = 0;

    bool possible = true;

    while(1) {
        if(SIsEmpty(S1) == true && SIsEmpty(S2) == true) {
            break;
        }
        else {
            if(SPeek(S1) == arr[arridx]) {
                if(SPeek(S2) < SPeek(S1)) { // S2는 오름차순 push
                    SPush(S2, SPop(S1));
                    pp[ppidx++] = '+';
                    SPop(S2);
                    pp[ppidx++] = '-';
                    arridx++;
                }
                else {
                    possible = false;
                    break;
                }
            }
            else if(SPeek(S2) == arr[arridx]) {
                SPop(S2);
                pp[ppidx++] = '-';
                arridx++;
            }
            else {
                if(SIsEmpty(S2)) {
                    SPush(S2, SPop(S1));
                    pp[ppidx++] = '+';
                }
                else{
                    if(SPeek(S2) < SPeek(S1)){
                        SPush(S2, SPop(S1));
                        pp[ppidx++] = '+';
                    }
                    else{
                        possible = false;
                        break;
                    }
                }
            }
        }
    }

    if(possible) {
        for(int i=0; i<ppidx; i++){
            printf("%c\n", pp[i]);
        }
    }
    else {
        printf("NO");
    }

}