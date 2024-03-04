#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char warr[51];
    int wlen;
}Word;

int mycmp(const void* w1, const void* w2){
    if((((Word*)w1)->wlen) == (((Word*)w2)->wlen))
        return strcmp(((Word*)w1)->warr, ((Word*)w2)->warr);
    else{
        if(((Word*)w1)->wlen > (((Word*)w2)->wlen))
            return 1;
        else
            return -1;
    }
}

Word Words[20000];

int main(void)
{
    int N;
    scanf("%d", &N);
    getchar();

    for(int i=0; i<N; i++){
        scanf("%s", Words[i].warr);
        Words[i].wlen = (int)strlen(Words[i].warr);
    }

    qsort(Words, N, sizeof(Word), mycmp);

    for(int i=0; i<N; i++){
        if(strcmp(Words[i].warr, Words[i+1].warr) != 0) // 중복 단어시 마지막것만 출력
            printf("%s\n", Words[i].warr);
    }

    return 0;

}