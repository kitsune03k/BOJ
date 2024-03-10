#include <stdio.h>
#include <stdlib.h>

#define FMAX 100000

typedef long long ll;

int main(void){
    int n;
    scanf("%d", &n);
    getchar();

    ll** arr = (ll**)malloc(sizeof(ll*) * n);
    for(int i=0; i<n; i++){
        arr[i] = (ll*)calloc(FMAX, sizeof(ll));
    }

    ll tmp;
    for(int i=0; i<n; i++){
        for(int j=0; j<FMAX; j++){
            scanf("%lld", &tmp);
            getchar();

            if(tmp != -1){
                arr[i][j] = tmp;
            }
            else{
                arr[i][j] = 0;
                break;
            }
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }



    int c = 0;
    for(c=0; c<FMAX; c++){
        if(arr[0][c] == arr[1][c] || arr[1][c] == arr[2][c] || arr[2][c] == arr[0][c]){ // 하나라도 같으면
            continue;
        }
        else{ // 전부 다르면
            break;
        }
    }

    printf("%d", c+1);

    for(int i=0; i<n; i++){
        free(arr[i]);
    }
    free(arr);

}