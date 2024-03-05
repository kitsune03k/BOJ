#include <stdio.h>

int main(void){
    for(int i=0; i<8; i++)
        for(int j=i+1; j<8; j++)
            for(int k=j+1; k<8; k++)
                printf("%d %d %d\n", i, j, k);

    return 0;
}
