#include <stdio.h>

typedef struct
{
    int Q;
    int D;
    int N;
    int P;
}Change;

int main(void)
{
    int T;
    scanf("%d", &T);

    int arr1[T];

    for(int i=0; i<T; i++){
        scanf("%d", &arr1[i]);
    }

    Change arr2[T];

    int Q, R;
    for(int i=0; i<T; i++){
        Q = 0; // Quotient
        R = 0; // Remainder

        int cents = arr1[i];

        arr2[i].Q = cents / 25;
        cents %= 25;

        arr2[i].D = cents / 10;
        cents %= 10;

        arr2[i].N = cents / 5;
        cents %= 5;

        arr2[i].P = cents / 1;
        cents %= 1;

        printf("%d %d %d %d\n", arr2[i].Q, arr2[i].D, arr2[i].N, arr2[i].P);
    }

    return 0;
}