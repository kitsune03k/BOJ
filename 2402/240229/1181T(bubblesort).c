#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LF printf("\n")

typedef struct{
    char warr[51];
    int wlen;
}Word;

void sort1(Word* mem[], int len) // wlen sort;
{
    Word* tmp;

    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1-i; j++){
            if(mem[j]->wlen > mem[j+1]->wlen){
                tmp = mem[j+1];
                mem[j+1] = mem[j];
                mem[j] = tmp;
            }
        }
    }
}

void sort2(Word* mem[], int len) // warr sort;
{
    Word *tmp;

    for(int i=0; i<len-1; i++) {
        for(int j=0; j<len-1-i; j++) {
            int cmprslt = strcmp(mem[j]->warr, mem[j+1]->warr);
            if(cmprslt > 0) {
                tmp = mem[j];
                mem[j] = mem[j + 1];
                mem[j + 1] = tmp;
            }
        }
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    Word* mem[N];

    Word* newWord;
    for(int i=0; i<N; i++){
        newWord = (Word*)calloc(sizeof(Word), 1);
        scanf("%s", newWord->warr);
        newWord->wlen = strlen(newWord->warr);
        mem[i] = newWord;
    }

    sort2(mem, N);
    sort1(mem, N);

    char* prev = "";
    for(int i=0; i<N; i++){
        if(strcmp(prev, mem[i]->warr)){
            printf("%s\n", mem[i]->warr);
        }
        prev = mem[i]->warr;
    }

    return 0;

}