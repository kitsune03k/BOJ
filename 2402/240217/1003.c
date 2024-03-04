#include <stdio.h>
#include <stdlib.h>

int main(void){
    int T;
    scanf("%d", &T);
    getchar();

    int answer[T][3];

    for(int i=0; i<T; i++){
        answer[i][0] = 0;
        answer[i][1] = 0;
        scanf("%d", &answer[i][2]);
    }
    getchar();

    int a, b, ab;

    for(int i=0; i<T; i++) {
        if(answer[i][2] == 0) {
            answer[i][0] = 1;
            answer[i][1] = 0;
        }
        else{
            a = 0;
            b = 1;

            for(int j=0; j<answer[i][2]-1; j++){
                ab = a + b;
                a = b;
                b = ab;
            }

            answer[i][0] = a;
            answer[i][1] = b;
        }
    }

    for(int i=0; i<T; i++){
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }
}