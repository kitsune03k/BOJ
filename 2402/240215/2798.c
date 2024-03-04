#include <stdio.h>

int main(void)
{
    int N, M;

    scanf("%d %d", &N, &M);
    getchar();

    int arr[N];
    for(int x=0; x<N; x++){
        scanf("%d", &arr[x]);
    }
    getchar();

    int answer = 0, sum;
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                sum = arr[i]+arr[j]+arr[k];

                if(sum <= M)
                    if(sum > answer)
                        answer = sum;
            }
        }
    }

    printf("%d", answer);
}