#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* arr = (char*)calloc(sizeof(char), 101);

    scanf("%s", arr);
    int slen = strlen(arr);
    int count = 0;

    char* cChar[8] = {"c=", "c-", "d-", "lj", "nj", "s=", "z=","dz="};


    for(int i=0; i<slen; i++)
    {
        char tmp[3] = {0,};
        for(int j=0; j<3; j++)
        {
            tmp[0] = arr[i];
            tmp[1] = arr[i+1];
            tmp[2] = arr[i+2];
        }

        for(int k=0; k<8; k++)
        {
            if(k != 7)
            {
                if(strncmp(tmp, cChar[k], 2) == 0)
                {
                    i = i+1;
                }
            }
            else // k == 7
            {
                if(strncmp(tmp, cChar[7], 3) == 0)
                {
                    i = i+2;
                }
            }
        }
        count++;
    }

    printf("%d", count);

    free(arr);

    return 0;
}
