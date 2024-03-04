#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 20

typedef struct
{
    char name[51]; // 최대 50글자
    double hour; // 실수형
    char grade[3]; // 최대 2글자
} Subject;

double convgrade(Subject* s)
{
    double ret = 0;
    if(s->grade[0] == 'F')
        return 0;

    ret += (double)(69 - s->grade[0]);
    if(s->grade[1] == '+')
        ret += 0.5;

    return ret;
}

int main(void)
{
    FILE* fp = fopen("25206-input1.txt", "rt");

    char* buf = (char*)calloc(sizeof(char), 60);

    double hrgr= 0.0;
    double hr = 0.0;
    for(int i=0; i<MAX_LEN; i++)
    {
        Subject s;
        for(int j=0; j<60; j++)
        {
            buf[j] = 0; // buf 매번 초기화
        }

        fgets(buf, 60, fp);
        sscanf(buf, "%*s %lf %s\n", &s.hour, s.grade);

        // Pass한 과목은 평점계산 제외
        if(strcmp(s.grade, "P") == 0)
        {
            continue;
        }

        double score = convgrade(&s);
        hrgr += (s.hour * score);
        hr += s.hour;
        printf("%lf(%s) * %lf = %lf\n", score, s.grade, hr, hrgr);

    }

    printf("%lf", hrgr/hr);

    free(buf);

    fclose(fp);

    return 0;

}