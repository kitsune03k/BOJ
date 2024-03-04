#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PN printf("\n")

int ref[100]; // 정방향, [N]
int refR[100]; // 역방향, [N]

int matchcount; // 매칭갯수
int matchidx[100]; // iref개

int arr[100][50]; // test cases, [T][N]


void show(int array[], int n)
{
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
}

bool issamepattern(int i1[], int i2[], int n){
    bool ret = true;

    for(int i=0; i<n; i++){
        if(i1[i] != i2[i]) {
            ret = false;
            break;
        }
    }

    return ret;
}


int main(void){

    /*** 1. 입력 ***/

    int N; // length
    scanf("%d", &N);
    getchar();

    int tmp;
    for(int j=0; j<N; j++){ // length
        scanf("%d", &tmp); // reference
        ref[j] = tmp;

        if(tmp < 3)
            refR[N-1-j] = ref[j]+2;
        else
            refR[N-1-j] = ref[j]-2;
    }
    getchar();

    int T; //cases
    scanf("%d", &T);
    getchar();

    for(int i=0; i<T; i++) { // cases
        for(int j = 0; j < N; j++) { // length
            scanf("%d", &arr[i][j]); // 각 row가 case
        }
    }


    /*** 2. array 편집 ***/

    // 1234 -> 1234123
    for(int j=0; j<N-1; j++){
        ref[j+N] = ref[j];
        refR[j+N] = refR[j];
    }


    /*** 3. 판독 ***/

    for(int i=0; i<T; i++){
        for(int j=0; j<N; j++){
            if(issamepattern(&ref[j], arr[i], N) || issamepattern(&refR[j], arr[i], N)){
                matchidx[matchcount++] = i;
                break;
            }
        }
    }

    printf("%d\n", matchcount);
    for(int i=0; i<matchcount; i++){
        show(arr[matchidx[i]], N);
        PN;
    }

    return 0;

}
