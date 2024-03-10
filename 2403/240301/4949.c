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

void SInit(Stack *S, int stsz) {
    S->arr = (Data *) malloc(sizeof(Data) * stsz + 1);
    memset(S->arr, 0, sizeof(Data) * stsz + 1);
    S->sz = stsz;
    S->numofdata = 0;
}

void SReset(Stack *S){
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


bool isbalanced(Stack *S, char arr[], int len) {
    bool ret = true;
    bool trigger = true;

    SReset(S);

    for(int i = 0; i < len; i++) {
        if(arr[i] == '(') {
            SPush(S, '(');
        }
        else if(arr[i] == ')') {
            Data popped = SPeek(S) == '(' ? SPop(S) : -1;

            if(popped == -1) {
                trigger = false;
                break;
            }
        }
        else if(arr[i] == '[') {
            SPush(S, '[');
        }
        else if(arr[i] == ']') {
            Data popped = SPeek(S) == '[' ? SPop(S) : -1;

            if(popped == -1) {
                trigger = false;
                break;
            }
        }
    }

    if(SIsEmpty(S) == false) {
        trigger = false;
    }

    if(trigger == false) {
        ret = false;
    }

    return ret;
}

int main(void) {
    Stack *S = (Stack *) malloc(sizeof(Stack));
    SInit(S, 100);
    char *yn[2] = {"no", "yes"};

    bool ans[10000];

    char *buf = (char*)malloc(sizeof(char) * 101);
    int t;
    for(t = 0;  ; t++) {
        memset(buf, 0, sizeof(char) * 101);

        int j;
        for(j = 0; j <= 100; j++) {
            scanf("%c", &buf[j]);

            if(buf[j] == '.') {
                break;
            }
        }
        getchar();

        if(buf[0] == '.')
            break;

        buf[j] = 0;

        ans[t] = isbalanced(S, buf, j);
    }

    for(int i = 0; i < t; i++) {
        printf("%s\n", yn[ans[i]]);
    }


    free(S);

    return 0;

}