#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char* src = (char*)calloc(sizeof(char), 100);
    char* dst = (char*)calloc(sizeof(char), 100);

    scanf("%s", src);

    for(int i=0; i<10; i++){
        dst[i] ^= src[i];
    }

    printf("src : %s\n", src);
    printf("dst : %s\n", dst);

    int tf = *src == *dst? 1 : 0;
    printf("%d", tf);

    printf("%c", *src);

    free(src);
    free(dst);
}