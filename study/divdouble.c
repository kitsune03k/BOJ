#include <stdio.h>

int main(void){

    long double x = 0.3;
    long double rx = x % 1;

    long double y = 0.7;
    long double ry = y % 1;

    long double z = -0.3;
    long double rz = z % 1;

    long double w = -0.7;
    long double rw = w % 1;

    printf("%Lf\n", rx); // 0
    printf("%Lf\n", ry); // 0
    printf("%Lf\n", rz); // 0
    printf("%Lf\n", rw); // 0
}