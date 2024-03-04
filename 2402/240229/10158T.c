#include <stdio.h>
#include <stdbool.h>

typedef unsigned int ui;

typedef struct{
    ui x;
    ui y;
} Pos;

typedef struct{
    int hor; // 1 우 -1 좌
    int ver; // 1 상 -1 하
} Dir;

typedef struct{
    Pos p;
    Dir d;
} Ant;

Pos lim; // NE방향 끝

Ant ant = {{-1, -1}, {1, 1} };

bool isendhor(){
    if(ant.p.x == lim.x || ant.p.x == 0)
        return true;
    else
        return false;
}

bool isendver(){
    if(ant.p.y == lim.y || ant.p.y == 0)
        return true;
    else
        return false;
}

void chdir(){
    if(isendhor() == true)
        ant.d.hor *= -1;
    if(isendver() == true)
        ant.d.ver *= -1;
}

void move(){
    chdir();

    ant.p.x += ant.d.hor;
    ant.p.y += ant.d.ver;
}

int main(void){
    scanf("%d %d", &lim.x, &lim.y);
    getchar();

    scanf("%d %d", &ant.p.x, &ant.p.y);
    getchar();

    ui t;
    scanf("%d", &t);
    getchar();


    for(int i=0; i<t; i++){
        move();
    }

    printf("%d %d", ant.p.x, ant.p.y);


    return 0;

}