#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef bool Data;

typedef struct {
    Data *arr;
    int sz;
    int numofdata;
} Stack;

void Stackinit(Stack *S, int stsz) {
    S->arr = (Data *) malloc(sizeof(Data) * stsz + 1);
    memset(S->arr, 0, sizeof(Data) * stsz + 1);
    S->sz = stsz;
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
        printf("nothing to peek!\n");
        return false;
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
        return false;
    }
}

void SPush(Stack *S, Data D) {
    if(SCount(S) <= S->sz) {
        S->numofdata++;
        S->arr[S->numofdata] = D;
    }
    else {
        //printf("memory exceed limit!\n");
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
        //printf("nothing to show!\n");
    }
}

int main(void) {
    Stack *S = (Stack *) malloc(sizeof(Stack));
    Stackinit(S, 100);

    char *yn[2] = {"NO", "YES"};

    int t;
    scanf("%d", &t);
    getchar();

    bool ans[t];
    memset(ans, true, sizeof(bool) * t);

    char buf[51];
    for(int i = 0; i < t; i++) {
        Stackinit(S, 100);
        memset(buf, 0, sizeof(char) * 51);
        bool trigger = true;

        scanf("%s", buf);
        getchar();

        int len = strlen(buf);
        buf[len] = 0;

        for(int j = 0; j < len; j++) {
            if(buf[j] == '('){
                SPush(S, true);
            }
            else if(buf[j] == ')'){
                bool ret = SPop(S);

                if(ret == false){
                    trigger = false;
                }
            }
        }

        if(SIsEmpty(S) == false)
            trigger = false;

        if(trigger == false){
            ans[i] = false;
        }
    }

    for(int i = 0; i < t; i++) {
        printf("%s\n", yn[ans[i]]);
    }

    free(S);

}