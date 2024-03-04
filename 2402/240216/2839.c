#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int answer = 1667;
    int threefive;
    for(int three = 0; three < 1667; three++){
        for(int five = 0; five < 1001; five++){
            if(3 * three + 5 * five == N){
                threefive = three+five;

                if(threefive <= answer){
                    answer = threefive;
                }
            }
        }
    }

    if(answer == 1667)
        answer = -1;

    printf("%d", answer);
}