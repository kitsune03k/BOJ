#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char str[101];

    bool answer = true;

    scanf("%s", str);
    int slen = strlen(str);


    for(int i = 0; i < slen/2; i++)
    {
        if(str[i] != str[(slen-1)-i])
        {
            answer = false;
        }
    }

    printf("%d", answer);

}