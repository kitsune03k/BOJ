#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Pos;

long double mypow(long double x, long double n)
{
    long double ret = 1.0;

    for(int i=0; i<n; i++){
        ret *= x;
    }

    return ret;
}

int compare(const void* x, const void* y)
{
    if(*(int*)x>*(int*)y)
        return 1;
    else
        return -1;
}


int main(void)
{
    int T;
    scanf("%d", &T);
    getchar();

    int answer[T];
    for(int i=0; i<T; i++){
        answer[i] = true;
    }

    Pos pos[4];

    bool filter[2];

    int xsum=0, ysum=0;
    long double cx, cy;
    long double sqcdis[4];

    unsigned long long sqdis[6];

    for(int try = 0; try<T; try++){
        for(int i=0; i<4; i++){
            scanf("%d %d", &pos[i].x, &pos[i].y);
            xsum += pos[i].x;
            ysum += pos[i].y;
            getchar();
        }


        // filter 1
        filter[0] = true;

        cx = (long double)xsum / 4.0;
        cy = (long double)ysum / 4.0;

        for(int i=0; i<4; i++){
            sqcdis[i] = mypow(
                    (cx-(long double)pos[i].x), 2) + mypow((cy-(long double)pos[i].y), 2);
        }

        for(int i=0; i<3; i++){
            if(sqcdis[i] != sqcdis[i+1]){
                filter[0] = false;
                break;
            }
        }


        // filter 2
        filter[1] = true;

        int idx = 0;
        for(int i=0; i<3; i++){
            for(int j=i+1; j<4; j++){
                sqdis[idx] =
                        (int)(
                                mypow((pos[i].x - pos[j].x), 2) +
                                mypow((pos[i].y - pos[j].y), 2)
                        );
                idx++;
            }
        }

        qsort(sqdis, 6, sizeof(unsigned long long), compare);

        for(int i=0; i<3; i++){
            int cmprslt = sqdis[i] == sqdis[i+1] ? true : false;

            if(cmprslt == 0){
                filter[1] = false;
                break;
            }
        }


        if(filter[0] == false || filter[1] == false)
            answer[try] = false;
    }

    for(int i=0; i<T; i++){
        printf("%d\n", answer[i]);
    }

    return 0;

}