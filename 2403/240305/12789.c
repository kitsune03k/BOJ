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


int main(void) {
    char *rslt[2] = {"Sad", "Nice"};

    Stack *S1 = (Stack *) malloc(sizeof(Stack));
    Stack *S2 = (Stack *) malloc(sizeof(Stack));
    StackInit(S1, 1000);
    StackInit(S2, 1000);
    S1->arr[0] = 1004;
    S2->arr[0] = 1004;

    int n;
    scanf("%d", &n);
    getchar();

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        getchar();
    }

    for(int i = n - 1; i >= 0; i--) {
        SPush(S1, arr[i]);
    } // S1이 시작 스텍, 다시 못 집어넣음

    bool possible = true;
    int count = 1;
    while(1) {
        if(SSize(S1) == 0 && SSize(S1) == 0) {
            break;
        }
        else {
            if(SPeek(S1) == count) {
                SPop(S1);
                count++;
            }
            else if(SPeek(S2) == count) {
                SPop(S2);
                count++;
            }
            else {
                if(SIsEmpty(S2)) { // S2가 비었을 때
                    SPush(S2, SPop(S1));
                }
                else { // S2가 비지 않았을때
                    if(SPeek(S2) > SPeek(S1)) {
                        SPush(S2, SPop(S1));
                    }
                    else {
                        possible = false;
                        break;
                    }
                }
            }
        }
    }

    printf("%s", rslt[possible]);

    free(S1->arr);
    free(S2->arr);
    free(S1);
    free(S2);


    return 0;


}
