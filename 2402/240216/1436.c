#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int count = 0;
    char* buf = (char*)calloc(sizeof(char), 10000000);
    char* answer = (char*)calloc(sizeof(char), 10000000);

    int slen;
    for(long long i=666;  ; i++){
        sprintf(buf,"%llu", i);
        slen = strlen(buf);

        int threesix = 0;
        for(long long j=0; j<slen-2; j++){
            if(buf[j] == '6' && buf[j+1] == '6' && buf[j+2] == '6'){
                count++;
                break;
            }
        }

        if(count == N) {
            strcpy(answer, buf);
            break;
        }
    }

    printf("%s", answer);

    return 0;
}