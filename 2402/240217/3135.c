#include <stdio.h>

int main(void)
{
    int A, B; // A에서 B로
    scanf("%d %d", &A, &B);
    getchar();

    int N;
    scanf("%d", &N);
    getchar();

    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    getchar();


    int gapMin, gapMinIdx;

    int gapAB;
    if(A < B){
        gapAB = B-A;
    }
    else{
        gapAB = A-B;

    }
    gapMin = gapAB;
    gapMinIdx = A;

    int gapN[N];
    for(int i=0; i<N; i++){
        if(arr[i] < B)
            gapN[i] = B-arr[i];
        else
            gapN[i] = arr[i]-B;

        if(gapN[i] < gapMin) {
            gapMin = gapN[i];
            gapMinIdx = arr[i];
        }
    }

    int answer = 0; // 원하는 주파수까지 버튼 누른 횟수

    if(gapMin == gapAB){ // 즐겨찾기가 다 이상한 곳에 있을 때
        answer = gapMin; // A부터 B까지 1MHz마다 버튼 눌러야함;;
    }
    else{ // 즐겨찾기가 유의미한 곳에 있을 때
        answer += 1; // 일단 즐겨찾기 버튼 한번 눌러야함
        if(gapMinIdx == B) // 즐겨찾기 버튼이 하필이면 B일때
            ;
        else if(gapMinIdx < B)
            answer += B - gapMinIdx;
        else // gapMinIdx > B)
            answer += gapMinIdx - B;

    }

    printf("%d", answer);

    return 0;

}