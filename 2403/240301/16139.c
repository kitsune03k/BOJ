#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main(void){
    char* arr = (char*)malloc(sizeof(char) * 200002);

    ull** abc = (ull**)malloc(sizeof(ull*) * 26);
    for(int i=0; i<26; i++){
        abc[i] = (ull*)malloc(sizeof(ull) * 200002);
    }

    char tmp;
    int cur;
    for(cur=1;  ; cur++){
        scanf("%c", &tmp);

        if(tmp == '\n'){
            arr[cur] = 0;
            break;
        }

        arr[cur] = tmp;
        int idx = tmp - 'a';
        (abc[idx])[cur]++;

        for(int row=0; row<26; row++){
            (abc[row])[cur] += (abc[row])[cur-1];
        }
    }
    cur--;

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


    for(int i=0; i<26; i++){
        free(abc[i]);
    }
    free(abc);
    free(arr);


    return 0;

}