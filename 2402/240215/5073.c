#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(int arr[], int sz)
{
    for(int i=0; i<sz-1; i++){
        for(int j=0; j<sz-1-i; j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

int main(void)
{
    char* words[4] = {"Equilateral", "Isosceles", "Scalene", "Invalid"};

    int* answer = (int*)calloc(sizeof(int),1000);

    int side[3];

    int i;
    for(i=0; ; i++){
        scanf("%d %d %d", &side[0], &side[1], &side[2]);
        getchar();
        if(side[0] == 0 && side[1] == 0 && side[2] == 0)
            break;

        bubblesort(side, 3);

        if(side[2] < side[1] + side[0]) {
            if(side[0] == side[1] && side[1] == side[2] && side[2] == side[0])
                answer[i] = 0;
            else{
                if(side[0] == side[1] || side[1] == side[2] || side[2] == side[0])
                    answer[i] = 1;
                else
                    answer[i] = 2;
            }
        }
        else {
            answer[i] = 3; // 삼각형 구성이 안됨
        }

    }

    for(int j=0; j<i; j++){
        printf("%s\n", words[answer[j]]);
    }

    free(answer);

}