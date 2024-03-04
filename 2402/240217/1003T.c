#include <stdio.h>

int fibonacci(int n, int answer[]) {
    if (n == 0) {
        answer[0]++;
        return 0;
    } else if (n == 1) {
        answer[1]++;
        return 1;
    } else {
        return fibonacci(n-1, answer) + fibonacci(n-2, answer);
    }
}

int main(void){
    int T;
    scanf("%d", &T);
    getchar();

    int answer[T][3];

    for(int i=0; i<T; i++) {
        answer[i][0] = 0;
        answer[i][1] = 0;

        scanf("%d", &answer[i][2]);
        getchar();

        fibonacci(answer[i][2], answer[i]);
    }

    for(int i=0; i<T; i++){
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }
}