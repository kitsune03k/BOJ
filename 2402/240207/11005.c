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

    for(int i=0; i<32; i++){
        Q = N/B;
        R = N%B;
        N /= B;

        arr[i] = itoc(R);

        if(Q == 0){
            break;
        }
        else{ // Q != 0
            if(Q < B){
                arr[i+1] = itoc(Q);
                break;
            }
        }
    }

    int slen = strlen(arr);

    for(int i=slen-1; i>=0; i--){
        printf("%c", arr[i]);
    }

}