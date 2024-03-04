#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int xmin;
    int ymin;
} Paper;

int main(void)
{
    int numPaper;
    scanf("%d", &numPaper);

    Paper p[numPaper];

    bool pp[100][100] = {false,};

    int x, y, answer = 0;

    for(int i=0; i<numPaper; i++){
        x = -1;
        y = -1;

        scanf("%d %d", &x, &y);

        for(int j=x; j<x+10; j++){
            for(int k=y; k<y+10; k++){
                if(pp[j][k] == false){
                    pp[j][k] = true;
                    answer++;
                }
            }
        }
    }

    printf("%d", answer);

}