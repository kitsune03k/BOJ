#include <stdio.h>

int main(void)
{
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j < 4 - i; j++){
            printf("[%d][%d]", j, j+1);
            printf(" ");
        }
        printf("\n");
    }

    for(int i = 5; i <= 9; i++) {
        for(int j = 5; j < 14 - i; j++) {
            printf("[%d][%d]", j, j+1);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
