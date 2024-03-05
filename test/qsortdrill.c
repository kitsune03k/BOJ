#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* x, const void* y)
{
    int sc = strcmp((char*)x, (char*)y);

    printf("%p vs %p : %d\n", (char*)x, (char*)y, sc);

    return sc;
}

int main(void)
{
    char* arr[] = {"grape", "egg", "flower", "christmas", "dog", "apple", "banana"};

    int sz = sizeof(arr)/sizeof(char*);
    printf("size : %d\n", sz);

    qsort(arr, sz, sizeof(char*), compare);

    for(int i=0; i<sz; i++){
        printf("%s\n", arr[i]);
    }
}