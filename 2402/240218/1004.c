#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
    int c;
}starpos;

long long square(long long x)
{
    long long ret = x*x;

    return ret;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    getchar();

    int answer[T];
    for(int i=0; i<T; i++){
        answer[i] = 0;
    }


    for(int i=0; i<T; i++){
        int startend[4];
        for(int j = 0; j < 4; j++){
            scanf("%d", &startend[j]);
        }
        getchar();

        int n;
        scanf("%d", &n);
        getchar();

        starpos stars[n];

        for(int j=0; j<n; j++){
            scanf("%d %d %d", &stars[j].x, &stars[j].y, &stars[j].c);
            getchar();

            int SQc = square(stars[j].c);
            int SQstart = square(startend[0]-stars[j].x)+square(startend[1]-stars[j].y);
            int SQend = square(startend[2]-stars[j].x)+square(startend[3]-stars[j].y);

            if(SQstart < SQc && SQend > SQc){
                answer[i]++;
            }

            if(SQend < SQc && SQstart > SQc){
                answer[i]++;
            }
        }
    }

    for(int i=0; i<T; i++){
        printf("%d\n", answer[i]);
    }
}