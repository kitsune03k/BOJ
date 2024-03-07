#include <stdio.h>

void fx1(int r, int c, char arr[][c]) { // 0, 360
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

void fx2(int r, int c, char arr[][c]) { // 45
    for(int t = 0; t < r + c; t++) {
        if(t < r) {
            for(int i = 0; i < (r - 1) - t; i++) {
                printf(" ");
            }
        }
        else {
            for(int i = 0; i < t - (r - 1); i++) {
                printf(" ");
            }
        }

        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                if(i + j == t) {
                    //printf("%d %d\n", j, i);
                    printf("%c ", arr[j][i]);
                }
            }
        }
        printf("\n");
    }
}

void fx3(int r, int c, char arr[][c]) { // 90
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            printf("%c", arr[r - 1 - j][i]);
        }
        printf("\n");
    }
}

void fx4(int r, int c, char arr[][c]) { // 135
    for(int t = 0; t < r + c; t++) {
        if(t < c) {
            for(int i = 0; i < (c - 1) - t; i++) {
                printf(" ");
            }
        }
        else {
            for(int i = 0; i < t - (c - 1); i++) {
                printf(" ");
            }
        }

        for(int i = r - 1; i >= 0; i--) {
            for(int j = 0; j < c; j++) {
                if((r - 1) - i + j == t) {
                    //printf("(%d %d) ", i, j);
                    printf("%c ", arr[i][j]);
                }
            }
        }
        printf("\n");
    }
}

void fx5(int r, int c, char arr[][c]) { // 180
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%c", arr[r - 1 - i][c - 1 - j]);
        }
        printf("\n");
    }
}

void fx6(int r, int c, char arr[][c]) { // 225
    for(int t = 0; t < r + c; t++) {

        if(t < r) {
            for(int i = 0; i < (r - 1) - t; i++) {
                printf(" ");
            }
        }
        else {
            for(int i = 0; i < t - (r - 1); i++) {
                printf(" ");
            }
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if((r - 1) - i + (c - 1) - j == t) {
                    //printf("(%d %d) ", i, j);
                    printf("%c ", arr[i][j]);
                }
            }
        }
        printf("\n");
    }
}

void fx7(int r, int c, char arr[][c]) { // 270
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            printf("%c", arr[j][c - 1 - i]);
        }
        printf("\n");
    }
}

void fx8(int r, int c, char arr[][c]) { // 315
    for(int t = 0; t < r + c; t++) {
        if(t < c) {
            for(int i = 0; i < (c - 1) - t; i++) {
                printf(" ");
            }
        }
        else {
            for(int i = 0; i < t - (c - 1); i++) {
                printf(" ");
            }
        }

        for(int i = 0; i < r; i++) {
            for(int j = c - 1; j >= 0; j--) {
                if(i + (c - 1) - j == t) {
                    //printf("(%d %d) ", i, j);
                    printf("%c ", arr[i][j]);
                }
            }
        }
        printf("\n");
    }
}

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);
    getchar();

    char arr[r][c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }

    int angle = 0;
    scanf("%d", &angle);
    getchar();

    angle /= 45;
    angle %= 8;

    //printf("angle = %d\n", angle);

    switch(angle) { // 시계방향으로 45도씩 회전
        case 0:
            fx1(r, c, arr);
            break;
        case 1:
            fx2(r, c, arr);
            break;
        case 2:
            fx3(r, c, arr);
            break;
        case 3:
            fx4(r, c, arr);
            break;
        case 4:
            fx5(r, c, arr);
            break;
        case 5:
            fx6(r, c, arr);
            break;
        case 6:
            fx7(r, c, arr);
            break;
        case 7:
            fx8(r, c, arr);
            break;
        default:;
    }
}