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
    int side[3];
    scanf("%d %d %d", &side[0], &side[1], &side[2]);

    bubblesort(side, 3);

    if(side[2] < side[1] + side[0]) {
        printf("%d", side[0]+side[1]+side[2]);
    }
    else{
        int longest = (side[0]+side[1]);
        printf("%d", side[0]+side[1]+(longest-1));
    }

}
