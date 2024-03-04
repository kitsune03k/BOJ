#include <stdio.h>

int main(void)
{
    // should be 1 1 2 2 2 8
    const int arr[6] = {1, 1, 2, 2, 2, 8};

    //char* input = "0 1 2 2 2 7";
    //char* input = "2 1 2 1 2 1";

    int num[6];
    scanf("%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);

    int pm[6];
    for(int i=0; i<6; i++)
    {
        pm[i] = arr[i] - num[i];
    }

    for(int i=0; i<6; i++)
    {
        printf("%d ", pm[i]);
    }

    return 0;
}
