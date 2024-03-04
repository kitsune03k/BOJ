#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* Words[3] = {"factor", "multiple", "neither"};

    int* Cases = (int*)calloc(sizeof(int),1000000);

    int a, b, i;

    for(i=0; ; i++){
        a = -1;
        b = -1;

        scanf("%d %d", &a, &b);

        if(a == 0 && b == 0)
            break;

        if(b%a == 0)
            Cases[i] = 0;
        else if(a%b == 0)
            Cases[i] = 1;
        else
            Cases[i] = 2;
    }

    for(int j=0; j<i; j++){
        printf("%s\n", Words[Cases[j]]);
    }
}