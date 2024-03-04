#include <stdio.h>

typedef struct{
    int row;
    int col;
} Pos;

int nextmove(int i){ // 0우, 1하, 2좌, 3상
    if(i == 3)
        return 0;
    else
        return i+1;
}

int movecur(Pos* cur, int mDir){
    if(mDir == 0)
        cur->col++;
    else if(mDir == 1)
        cur->row++;
    else if(mDir == 2)
        cur->col--;
    else if(mDir == 3)
        cur->row--;
}


int main(void){
    int N, K;
    scanf("%d", &N);
    getchar();
    scanf("%d", &K);
    getchar();

    int arr[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            arr[i][j] = 0;

    Pos cur = {N/2+1, N/2};
    Pos tgt; // 찾는 값의 좌표, 0부터 시작
    arr[cur.row][cur.col] = 1;

    int mDis = 0;
    int mCount = 0;
    int mDir = 3; // 방향
    for(int i=1; i<=N*N; i++){
        if(mDir == 0 && mCount == 0) {
            cur.row--;
            cur.col--;
        }
        movecur(&cur, mDir);
        arr[cur.row][cur.col] = i;
        mCount++;

        if(i == K){
            tgt.row = cur.row+1;
            tgt.col = cur.col+1;
        }

        if(mCount >= mDis){
            if(mDir == 3){
                mDis+=2;
            }
            mDir = nextmove(mDir);
            mCount = 0;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("%d %d", tgt.row, tgt.col);

    return 0;
}