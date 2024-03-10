#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
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

int GetOpPrec(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;   // 등록되지 않은 연산자
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if(op1Prec > op2Prec)
		return 1;
	else if(op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1);

	int i, idx=0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen+1);
	StackInit(&stack, 100);

	for(i=0; i<expLen; i++)
	{
		tok = exp[i];
		if(tok >= 'A' && tok <= 'Z')
		{
			convExp[idx++] = tok;
		}
		else
		{
			switch(tok)
			{
			case '(':
				SPush(&stack, tok);
				break;

			case ')':
				while(1)
				{
					popOp = SPop(&stack);
					if(popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while(!SIsEmpty(&stack) &&
						WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;
			}
		}
	}

	while(!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}


int main(void)
{
    char exp[100];
    memset(exp, 0, sizeof(char) * 100);
    scanf("%s", exp);

	ConvToRPNExp(exp);

	printf("%s", exp);

}