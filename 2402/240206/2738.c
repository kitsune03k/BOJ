#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    getchar();

    int arr1[x][y], arr2[x][y];

    char tmp[4*y];

    for(int i=0; i<x; i++)
    {
        for(int t=0; t<4*y; t++)
        {
            tmp[t] = 0;
        }

        scanf("%[^\n]", tmp);
        getchar();

        char* token = strtok(tmp, " ");

        int col = 0;
        while(token)
        {
            int tokenint = atoi(token);
            arr1[i][col] = tokenint;
            col++;
            token = strtok(NULL, " ");
        }
    }

    for(int i=0; i<x; i++)
    {
        for(int t=0; t<4*y; t++)
        {
            tmp[t] = 0;
        }

        scanf("%[^\n]", tmp);
        getchar();

        char* token = strtok(tmp, " ");

        int col = 0;
        while(token)
        {
            int tokenint = atoi(token);
            arr2[i][col] = tokenint;
            col++;
            token = strtok(NULL, " ");
        }
    }

    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            printf("%d ", arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
    }
}
