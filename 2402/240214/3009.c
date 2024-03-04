#include <stdio.h>

int main(void)
{
    int arr[4][2];
    /*
    x1 y1
    ...
    x4 y4
    */

    for(int i=0; i<3; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        getchar();
    }
    
    if(arr[0][0] == arr[1][0])
        arr[3][0] = arr[2][0];
    else if(arr[0][0] == arr[2][0])
        arr[3][0] = arr[1][0];
    else if(arr[1][0] == arr[2][0])
        arr[3][0] = arr[0][0];

    if(arr[0][1] == arr[1][1])
        arr[3][1] = arr[2][1];
    else if(arr[0][1] == arr[2][1])
        arr[3][1] = arr[1][1];
    else if(arr[1][1] == arr[2][1])
        arr[3][1] = arr[0][1];
            
    printf("%d %d", arr[3][0], arr[3][1]);

    return 0;

}
