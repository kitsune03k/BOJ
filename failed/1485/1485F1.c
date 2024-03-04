#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int x;
    int y;
} Pos;

int main(void)
{
    int T;
    scanf("%d", &T);
    getchar();

    int answer[T];
    for(int i=0; i<T; i++){
        answer[i] = 0;
    }

    Pos pos[4];
    Pos sq[2][2];
    for(int try = 0; try<T; try++){
        bool issq[2][2] = {false};

        for(int i=0; i<4; i++){
            scanf("%d %d", &pos[i].x, &pos[i].y);
            getchar();
        }

        int xmin = 100001, xmax = -100001, ymin = 100001, ymax = -100001;
        for(int i=0; i<4; i++) {
            if(pos[i].x < xmin)
                xmin = pos[i].x;
            if(pos[i].x > xmax)
                xmax = pos[i].x;
            if(pos[i].y < ymin)
                ymin = pos[i].y;
            if(pos[i].y > ymax)
                ymax = pos[i].y;
        }

        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                if(i == 0){
                    sq[i][j].y = ymax;
                } else {
                    sq[i][j].y = ymin;
                }
                if(j == 0){
                    sq[i][j].x = xmin;
                } else {
                    sq[i][j].x = xmax;
                }
            }
        }


        for(int i=0; i<4; i++){
            int x = pos[i].x;
            int y = pos[i].y;

            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++){
                    if((x == sq[j][k].x && y == sq[j][k].y)){
                        issq[j][k] = true;
                    }
                }
            }
        }

        bool ret = true;

        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                if(!issq[i][j])
                    ret = false;
            }
        }

        answer[try] = ret;
    }

    for(int i=0; i<T; i++){
        printf("%d\n", answer[i]);
    }

    return 0;

}