#include <stdio.h>

typedef struct{
    int x;
    int y;
} Pos;

Pos chamwae[6];
Pos rec[2][2];
Pos nopos;
Pos centerpos;

int main(void)
{
    int efficency;
    scanf("%d", &efficency);

    Pos tmp;
    tmp.x = 0;
    tmp.y = 0;
    int compass, length;
    for(int i=0; i<6; i++){
        scanf("%d %d", &compass, &length);
        if(compass == 1){
            tmp.x += length;
        }
        else if(compass == 2){
            tmp.x -= length;
        }
        else if(compass == 3){
            tmp.y -= length;
        }
        else if(compass == 4){
            tmp.y += length;
        }
        else
            return -1;

        chamwae[i].x = tmp.x;
        chamwae[i].y = tmp.y;
    }

    printf("\n");
    for(int i=0; i<6; i++){
        printf("(%d, %d) ", chamwae[i].x, chamwae[i].y);
    }

    int xmin = 1000, xmax = -1000, ymin = 1000, ymax = -1000;
    int x, y;

    for(int i=0; i<6; i++){
        int x = chamwae[i].x, y = chamwae[i].y;

        if(x < xmin)
            xmin = x;
        if(x > xmax)
            xmax = x;

        if(y < ymin)
            ymin = y;
        if(y > ymax)
            ymax = y;
    }

    printf("%d %d %d %d\n", xmin, xmax, ymin, ymax);

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            if(i == 0)
                rec[i][j].y = ymax;
            else
                rec[i][j].y = ymin;

            if(j == 0)
                rec[i][j].x = xmin;
            else
                rec[i][j].x = xmax;
            printf("[(%d, %d)] ", rec[i][j].x, rec[i][j].y);
        }
        printf("\n");
    }


    int noposfind = 0;

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            x = rec[i][j].x, y = rec[i][j].y;
            int find = 0;

            for(int k=0; k<6; k++){
                if(chamwae[k].x == x && chamwae[k].y == y) {
                    find = 1;
                    break;
                }
            }

            if(!find){
                nopos.x = x;
                nopos.y = y;
                noposfind = 1;
            }

            if(noposfind)
                break;
        }
        if(noposfind)
            break;
    }

    for(int i=0; i<6; i++){
        x = chamwae[i].x, y = chamwae[i].y;

        if(x != xmin && x != xmax && y != ymin && y != ymax){
            centerpos.x = x;
            centerpos.y = y;
            break;
        }
    }

    int area1 = (xmax - xmin) * (ymax - ymin);

    int a2x, a2y;

    if(centerpos.x > nopos.x)
        a2x = centerpos.x - nopos.x;
    else
        a2x = nopos.x - centerpos.x;

    if(centerpos.y > nopos.y)
        a2y = centerpos.y - nopos.y;
    else
        a2y = nopos.y - centerpos.y;


    int area2 = a2x * a2y;

    printf("%d", efficency*(area1 - area2));


}