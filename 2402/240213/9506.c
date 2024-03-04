#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int num;
    int* yaksu;
    int ycount;
    int ysum;
    bool p;
}NUM;

int main(void)
{
    NUM* arr[10000];

    int X;

    int count;
    for(count=0; ; count++){
        scanf("%d", &X);
        getchar();

        if(X == -1)
            break;

        NUM* nn = (NUM*)calloc(sizeof(NUM), 1);
        nn->num = X;
        nn->yaksu = (int*)calloc(sizeof(int), X);
        nn->ycount = 0;
        nn->ysum = 0;
        nn->p = false;

        arr[count] = nn;
    }

    int n1;
    int* yarr1;
    for(int i=0; i<count; i++){
        n1 = arr[i]->num;
        yarr1 = arr[i]->yaksu;

        for(int j=1; j<n1; j++){
            if(n1%j == 0){
                yarr1[arr[i]->ycount++] = j;
                arr[i]->ysum += j;
            }
        }

        if(arr[i]->ysum == arr[i]->num) // 완전수일경우
            arr[i]->p = true;
    }

    int n2, yc;
    int* yarr2;
    for(int i=0; i<count; i++){
        n2 = arr[i]->num;
        yarr2 = arr[i]->yaksu;
        yc = arr[i]->ycount;

        if(arr[i]->p == true){
            printf("%d = ", n2);

            for(int j=0; j<yc; j++){
                printf("%d", yarr2[j]);

                if(j != yc-1)
                    printf(" + ");
            }
        }
        else{
            printf("%d is NOT perfect.", n2);
        }

        printf("\n");
    }

    return 0;
}