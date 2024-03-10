#include <stdio.h>

char arr[2001];
unsigned long long abc[26][2001];

int main(void){
    char tmp;
    int cur;
    for(cur=1;  ; cur++){
        scanf("%c", &arr[cur]);

        if(arr[cur] == '\n'){
            arr[cur] = 0;
            break;
        }

        abc[arr[cur]-'a'][cur]++;

        for(int row=0; row<26; row++){
            abc[row][cur] += abc[row][cur-1];
        }
    }
    cur--;
/*
    printf("\n   ch  ");
    for(int i=1; i<=cur; i++){
        printf("%4c ", arr[i]);
    }
    printf("\n   idx ");
    for(int i=0; i<cur; i++){
        printf("%4d ", i);
    }
    printf("\n");

    for(int i=0; i<26; i++){
        printf("%4c : ", i+'a');
        for(int j=1; j<=cur; j++) {
            printf("%4d ", abc[i][j]);
        }
        printf("\n");
    }
*/
    int q;
    scanf("%d", &q);
    getchar();

    unsigned long long ans[q];

    char ch;
    int start, end;
    for(int i=0; i<q; i++){
        scanf("%c %d %d", &ch, &start, &end);
        getchar();

        ans[i] = abc[ch-'a'][end+1] - abc[ch-'a'][start];
    }

    for(int i=0; i<q; i++){
        printf("%llu\n", ans[i]);
    }
}