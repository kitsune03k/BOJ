#include <stdio.h>
#include <stdbool.h>

char arr1[100][100]; // 일반
bool checked1[100][100];

char arr2[100][100]; // 적록색약
bool checked2[100][100];

int dfs1(int i, int j, int n, char rgb){

    // 재귀시 범위 제한, main에서 실행시 바로 통과
    if(i < 0 || i >= n || j < 0 || j >= n){
        return 0;
    }

    // 재귀시 대상 탐색, main에서 실행시 바로 통과
    if(arr1[i][j] != rgb) {
        return 0;
    }

    if(checked1[i][j] == false){
        checked1[i][j] = true;

        dfs1(i-1, j, n, rgb);
        dfs1(i+1, j, n, rgb);
        dfs1(i, j-1, n, rgb);
        dfs1(i, j+1, n, rgb);

        return 1;
    }
    else{
        return 0;
    }
}

int dfs2(int i, int j, int n, char rgb){

    // 재귀시 범위 제한
    if(i < 0 || i >= n || j < 0 || j >= n){
        return 0;
    }

    // 재귀시 대상 탐색
    if(arr2[i][j] != rgb) {
        return 0;
    }

    if(checked2[i][j] == false){
        checked2[i][j] = true;

        dfs2(i-1, j, n, rgb);
        dfs2(i+1, j, n, rgb);
        dfs2(i, j-1, n, rgb);
        dfs2(i, j+1, n, rgb);

        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    getchar();

    char tmp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%c", &tmp);

            if(tmp == 'B'){
                arr1[i][j] = 'B';
                arr2[i][j] = 'B';
            }
            else if(tmp == 'R'){
                arr1[i][j] = 'R';
                arr2[i][j] = '.';
            }
            else if(tmp == 'G'){
                arr1[i][j] = 'G';
                arr2[i][j] = '.';
            }
        }
        getchar();
    }

    int a1 = 0, a2 = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a1 += dfs1(i, j, n, arr1[i][j]);
            a2 += dfs2(i, j, n, arr2[i][j]);
        }
    }

    printf("%d %d", a1, a2);


}