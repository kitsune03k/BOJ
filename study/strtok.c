#include <stdio.h>
#include <string.h>

#define PT printf("tok : %s\n", tok)

int main(void){
    char str[] = "U original ittkii,kami";
    char* tok = strtok(str, " ");
    PT;
    tok = strtok(NULL, " ");
    PT;
    tok = strtok(NULL, ",");
    PT;
    tok = strtok(NULL, ",");
    PT;
}