#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keyboard[4][13] = {
    {'`','1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
    {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
    {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', 0, 0,},
    {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', 0, 0, 0,}
};

char qwerty(char c){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            if(keyboard[i][j] == c) {
                return keyboard[i][j - 1];
            }
        }
    }

    return c; // array keyboard에 없을 경우
}

int main(void)
{
    char* arr = (char*)calloc(sizeof(char), 1000000);


    while(1){
        for(int i=0; i<1000000; i++)
            arr[i] = 0;

        scanf("%[^\n]", arr);
        getchar();

        if(strlen(arr) == 0)
            break;

        int i = 0;
        while(arr[i] != 0) {
            printf("%c", qwerty(arr[i++]));
        }
        printf("\n");
    }

    free(arr);

    return 0;

}