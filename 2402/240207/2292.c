#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);

    if(x == 1){
        printf("%d", 1);
        return 0;
    }

    for(int i = 1; ; i++)
    {
        int S = 3 * i * i - 3 * i + 2;
        int E = 3 * i * i + 3 * i + 2;

        if(x >= S && x < E){
            printf("%d", i+1);
            break;
        }
    }

    return 0;
}
