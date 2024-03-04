#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[51]; // 최대 50글자
    double hour; // 실수형
    char grade[3]; // 최대 2글자
} Subject;

double convgrade(Subject* s)
{
    if(s->grade[0] == 'F')
        return 0;

    double ret = 0;
    ret += (double)(69 - s->grade[0]);
    if(s->grade[1] == '+')
        ret += 0.5;

    return ret;
}

int main(void)
{
    double hrgr= 0.0;
    double hr = 0.0;

    for(int i=0; i<20; i++)
    {
        Subject s;

        scanf("%s %lf %s", s.name, &s.hour, s.grade);

        if(strlen(s.name) == 0)
            break;

        // Pass한 과목은 평점계산 제외
        if(strcmp(s.grade, "P") == 0)
        {
            continue;
        }

        double score = convgrade(&s);
        hrgr += (s.hour * score);
        hr += s.hour;
    }

    printf("%lf", hrgr/hr);

    return 0;

}