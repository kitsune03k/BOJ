#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long long ull;

typedef struct {
    long long x;
    long long y;
} Pos;

void calcdis(Pos *pp1, Pos *pp2, ull *pull) {
    ull disx = (pp1->x - pp2->x)*(pp1->x - pp2->x);
    ull disy = (pp1->y - pp2->y)*(pp1->y - pp2->y);
    *pull = disx + disy;
};

bool istri(Pos *p1, Pos *p2, Pos *p3) {
    ull dis[3];

    calcdis(p1, p2, &dis[0]);
    calcdis(p2, p3, &dis[1]);
    calcdis(p3, p1, &dis[2]);

    if(dis[0] + dis[1] == dis[2] || dis[1] + dis[2] == dis[0] || dis[2] + dis[0] == dis[1]) {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    getchar();

    Pos *arr = (Pos *) malloc(sizeof(Pos) * n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
        getchar();
    }

    int ans = 0;

    for(int p = 0; p < n - 2; p++) {
        for(int q = p + 1; q < n - 1; q++) {
            for(int r = q + 1; r < n; r++) {
                if(istri(&arr[p], &arr[q], &arr[r]))
                    ans++;
            }
        }
    }

    printf("%d", ans);

    free(arr);

    return 0;
}