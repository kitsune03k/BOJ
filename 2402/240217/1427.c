#include <stdio.h>
#include <string.h>
int bsort(char arr[], int length)
{
    char tmp;
    for(int i=0; i<length-1; i++){
        for(int j=0; j<length-1-i; j++){
            if(arr[j]<arr[j+1]){
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(void)
{
    char arr[12] = {0,};

    scanf("%s", arr);
    getchar();

    bsort(arr, strlen(arr));

    printf("%s", arr);
}