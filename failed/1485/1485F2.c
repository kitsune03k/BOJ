#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Pos;

int main(void) {
    int T;
    scanf("%d", &T);
    getchar();

    int answer[T];
    for(int i = 0; i < T; i++) {
        answer[i] = 0;
    }

    Pos pos[4];
    Pos sq[2][2];
    for(int try = 0; try < T; try++) {
        bool issq[2][2] = {false};

        for(int i = 0; i < 4; i++) { // 점 4개 입력받음
            scanf("%d %d", &pos[i].x, &pos[i].y);
            getchar();
        }

        int xmin = 100001, xmax = -100001, ymin = 100001, ymax = -100001;
        for(int i = 0; i < 4; i++) { // 최대값 최소값 골라냄
            if(pos[i].x < xmin) {
                xmin = pos[i].x;
            }
            if(pos[i].x > xmax) {
                xmax = pos[i].x;
            }
            if(pos[i].y < ymin) {
                ymin = pos[i].y;
            }
            if(pos[i].y > ymax) {
                ymax = pos[i].y;
            }
        }

        for(int i = 0; i < 2; i++) { // 최대최소가 타당하다면, 이를 통한 사각형 좌표 생성
            for(int j = 0; j < 2; j++) {
                if(i == 0) {
                    sq[i][j].y = ymax;
                }
                else {
                    sq[i][j].y = ymin;
                }
                if(j == 0) {
                    sq[i][j].x = xmin;
                }
                else {
                    sq[i][j].x = xmax;
                }
            }
        }

        if(ymax - ymin != xmax - xmin) {
            answer[try] = false;
        }
        else {
            int ret = true;

            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    int x = sq[i][j].x;
                    int y = sq[i][j].y;

                    for(int k = 0; k < 4; k++) {
                        if(pos[k].x == x && pos[k].y == y) {
                            issq[i][j] = true;
                        }
                    }
                }
            }

            for(int i = 0; i < 2; i++) { // 최대최소 사각형 구성하는 점 하나라도 없을경우
                for(int j = 0; j < 2; j++) {
                    if(!issq[i][j]) {
                        ret = false;
                        break;
                    }
                }
            }

            answer[try] = ret;
        }
    }

    for(int i = 0; i < T; i++) {
        printf("%d\n", answer[i]);
    }

    return 0;

}