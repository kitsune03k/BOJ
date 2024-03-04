#include <stdio.h>
#include <string.h>

char itoc(int R)
{
    if(R<10)
        return (char)(R+48);
    else
        return (char)(R+55);
}

int main(void)
{
    int N, B;
    scanf("%d %d", &N, &B);

    char arr[64] = {0,};

    int Q, R; // Quotient, Remainder
#if DEBUG
    for(int i1=1; i1<65536; i1++)
    {
        N = i1;
        B = 16;
#endif
    for(int i=0; i<32; i++){
        Q = N/B;
        R = N%B;

        printf("%d / %d = %d ... %d", N, B, Q, R);

        N /= B;

        printf(", new N : %d\n", N);

        arr[i] = itoc(R);

        if(Q == 0){
            break;
        }
        else{ // Q != 0
            if(Q < B){
                arr[i+1] = itoc(Q);
                printf("last : %d\n", Q);
                break;
            }
        }

    }

    int slen = strlen(arr);
    printf("slen : %d\n", slen);

    for(int i=slen-1; i>=0; i--)
    {
        printf("%c", arr[i]);
    }
#if DEBUG
    printf("\n");
    }
#endif


}