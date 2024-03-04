#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define ULL unsigned long long
#define LD long double

typedef struct{
    int xpos;
    int ypos;
} Pos;

int compare(const void* x1, const void* x2){
    if(*(LD*)x1 == *(LD*)x2)
        return 0;
    else{
        if(*(LD*)x1 > *(LD*)x2)
            return 1;
        else
            return -1;
    }
}

LD dist(Pos* p1, Pos* p2){
    ULL sqhor = (p1->xpos-p2->xpos)*(p1->xpos-p2->xpos);
    ULL sqver = (p1->ypos-p2->ypos)*(p1->ypos-p2->ypos);
    return sqrtl((LD)(sqhor+sqver));
}

Pos arr[3];
LD d[3];
LD pd[3]; // 어떤 점과 대칭되는 점을 가진 평행사변형 길이

bool ispossible(){
    if(d[0] != 0 && d[1] != 0 && d[2] != 0) { // 어떤 두 점이 중첩이 없을때
        if(d[0] + d[1] > d[2]) {
            return true;
        }
        else {
            return false;
        }
    }
    else{ // 어떤 두 점이 중첩 될 때
        return false;
    }
}

int main(void){
    for(int i=0; i<3; i++){
        scanf("%d", &arr[i].xpos);
        scanf("%d", &arr[i].ypos);
    }

    d[0] = dist(&arr[1], &arr[2]);
    d[1] = dist(&arr[0], &arr[2]);
    d[2] = dist(&arr[0], &arr[1]);

    pd[0] = (LD)2*(d[1]+d[2]);
    pd[1] = (LD)2*(d[0]+d[2]);
    pd[2] = (LD)2*(d[0]+d[1]);

    qsort(d, 3, sizeof(LD), compare);
    qsort(pd, 3, sizeof(LD), compare);

    if(ispossible()){
        printf("%.12Lf", (LD)(pd[2]-pd[0]));
    }
    else{
        printf("%.1f", (float)-1);
    }


    return 0;

}