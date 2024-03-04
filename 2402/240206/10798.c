#include <stdio.h>
#include <string.h>

int main(void)
{
    int slen = 0;
    char arr[5][16] = {0,};

    for(int i=0; i<5; i++){
        scanf("%s", arr[i]);

        int ilen = strlen(arr[i]);
        if(ilen > slen){
            slen = ilen;
        }
    }

    for(int i=0; i<slen; i++){
        for(int j=0; j<5; j++){
            char ch = arr[j][i];
            if(ch != 0){
                printf("%c", ch);
            }
        }
    }

}