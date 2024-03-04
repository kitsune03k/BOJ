#include <stdio.h>

int main(void)
{
    char* words[4] = {"Equilateral", "Isosceles", "Scalene", "Error"};

    int angle[3];

    for(int i = 0; i < 3; i++) {
        scanf("%d", &angle[i]);
        getchar();
    }


    if(angle[0] + angle[1] + angle[2] == 180) {
        if(angle[0] == angle[1] && angle[1] == angle[2] && angle[2] == angle[0])
            printf("%s", words[0]);
        else if(angle[0] == angle[1] || angle[1] == angle[2] || angle[2] == angle[0])
            printf("%s", words[1]);
        else
            printf("%s", words[2]);
    }
    else{
        printf("%s", words[3]);
    }

    return 0;
}