#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long ncr(int n, int r) {
    unsigned long long ret = 1;

    int nr = n - r;
    int div1, div2; // div1 < div2, div1 + div2 = n

    if(nr < r) {
        div1 = nr;
        div2 = r;
    }
    else { // nr >= r
        div1 = r;
        div2 = nr;
    }

    unsigned long long k = 1, kref = 1;

    for(int i = div2 + 1; i <= n; i++) {
        ret *= i;
        k *= kref++;
    }

    return ret / k;
}

int main(void)
{
    char arr[51];
    scanf("%s", arr);
    arr[50] = 0;

    int len = strlen(arr);
    int cases = ncr(len-1, 2);

    char* Words[cases];


    int Widx = 0;
    for(int p=0; p<len-2; p++){
        for(int q=p+1; q<len-1; q++){
            int idx = 0;
            char* newWord = (char*)calloc(sizeof(char), len+1);
            int div1 = p, div2 = q;

            for(int i=div1; i>=0; i--){
                newWord[idx++] = arr[i];
            }

            for(int i=div2; i>div1; i--){
                newWord[idx++] = arr[i];
            }

            for(int i=len-1; i>div2; i--){
                newWord[idx++] = arr[i];
            }

            //printf("%s\n", newWord);
            Words[Widx++] = newWord;
        }
    }

    char* toprint = Words[0];

    for(int i=0; i<cases; i++){
        if(strcmp(toprint, Words[i]) > 0)
            toprint = Words[i];
    }

    printf("%s", toprint);

    return 0;

}