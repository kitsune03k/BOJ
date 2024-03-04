#include <stdio.h>

#define PN printf("\n")

int arr[1500][1500];
int head[1500]; // 자료가 x개 있다. (= idx + 1)

void show(int N)
{
    PN;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", arr[i][j]);
        }
        PN;
    }
    for(int i=0; i<N; i++){
        printf("---");
    }
    PN;
    for(int i=0; i<N; i++){
        printf("%d ", head[i]);
    }
    PN;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    getchar();

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
            head[j]++;
        }
    }

    int smax;

    for(int k=0; k<N; k++){
        smax = -1234567890;

        int peekint, peekidx;
        for(int i = 0; i < N; i++) { // i = column;
            if (head[i] > 0)
                peekint = arr[head[i]-1][i];
            else
                peekint = -1;
            if(peekint > smax) {
                smax = peekint;
                peekidx = i;
            }
        }
        head[peekidx]--;
    }

    printf("%d", smax);

    return 0;

}