#include <stdio.h>
#include <string.h>

char name[51];
char palindrome[51];

int abc[26];

int main(void) {
    scanf("%s", name);
    getchar();

    unsigned long long nlen = strlen(name);
    for(int i = 0; i < nlen; i++) {
        abc[name[i] - 'A']++;
    }

    int oddcount = 0;
    for(int i = 0; i < 26; i++) {
        if(abc[i] % 2 != 0) {
            oddcount++;
        }
    }

    if(oddcount > 1) {
        printf("I'm Sorry Hansoo");
    }
    else {
        int pidx = 0;
        for(int i = 0; i < 26; i++) { // 알파뱃 관련
            if(abc[i] != 0) {
                for(int j = 0; j < abc[i] / 2; j++) { // 횟수 관련, 무조건 abc[i]는 0이 아닌 짝수번
                    palindrome[pidx++] = (char) (i + 'A');
                }
            }
        }

        if(oddcount == 1) {
            int oddidx;

            for(int i = 0; i < 26; i++) {
                if(abc[i] % 2 != 0) {
                    oddidx = i;
                }
            }
            palindrome[pidx] = (char) (oddidx + 'A');
        }

        for(int i = 0; i < nlen / 2; i++) {
            palindrome[nlen - 1 - i] = palindrome[i];
        } // 좌우 데칼코마니

        for(int i = 0; i < nlen; i++) {
            printf("%c", palindrome[i]);
        }
    }


    return 0;
}