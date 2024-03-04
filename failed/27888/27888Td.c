#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PT printf("tok : %s\n", tok)

typedef struct _Feature {
    char *fname;
    struct _Feature *next;
} Feature;

typedef struct _Station {
    char *sname;
    Feature *fhead; // dmy
    Feature *cur;
    int numoffeat;
} Station;

bool mystrcmp(char *s1, char *s2, int len) {
    bool ret = true;

    for(int i = 0; i < len; i++) {
        if(s1[i] != s2[i]) {
            ret = false;
            break;
        }
    }

    return ret;
}

Station *SInit(char *sname) {
    Station *newStation = (Station *) malloc(sizeof(Station));
    int slen = strlen(sname);

    newStation->sname = (char *) malloc(sizeof(char) * (slen + 1));
    memset(newStation->sname, 0, sizeof(char) * (slen + 1));
    for(int i = 0; i <= slen; i++) {
        newStation->sname[i] ^= sname[i];
    }

    newStation->fhead = (Feature *) malloc(sizeof(Feature)); // dmy
    newStation->fhead->next = NULL;
    newStation->cur = newStation->fhead; // 처음 커서는 더미를 가리킴

    newStation->numoffeat = 0;

    return newStation;
}

void SFeatAddFirst(Station *S, char *fname) { // 리셋 후 처음 하나
    Feature *newFeature = (Feature *) malloc(sizeof(Feature));
    int flen = strlen(fname);

    newFeature->fname = (char *) malloc(sizeof(char) * (flen + 1));
    memset(newFeature->fname, 0, sizeof(char) * (flen + 1));
    for(int i = 0; i < flen; i++) {
        newFeature->fname[i] ^= fname[i];
    }

    newFeature->next = NULL;
    S->fhead->next = newFeature; /*** 원래 있던 dmy 다음 첫 노드와 연결을 끊어준다! ***/
    S->cur = newFeature;
    S->numoffeat++;
}

void SFeatAddNext(Station *S, char *fname) { // 이어서
    Feature *newFeature = (Feature *) malloc(sizeof(Feature));
    int flen = strlen(fname);

    newFeature->fname = (char *) malloc(sizeof(char) * (flen + 1));
    memset(newFeature->fname, 0, sizeof(char) * (flen + 1));
    for(int i = 0; i < flen; i++) {
        newFeature->fname[i] ^= fname[i];
    }

    newFeature->next = NULL;
    S->cur->next = newFeature; /*** 커서(마지막 노드)에 만든 노드를 이어준다! ***/
    S->cur = newFeature;
    S->numoffeat++;
}


bool SFeatSearch(Station *S, char *fname) {
    bool ret = false;
    Feature *fptr = S->fhead->next;

    while(fptr != NULL) {
        bool tf = mystrcmp(fname, fptr->fname, strlen(fname));

        if(tf == true) {
            ret = true;
            break;
        }

        fptr = fptr->next;
    }
    return ret;
}

#if DEBUG
void Dshow(Station *S[], int n) { // for debug
    for(int i = 0; i < n; i++) {
        printf("%s : ", S[i]->sname);

        Feature *fptr = S[i]->fhead->next;
        while(fptr != NULL) {
            printf("%s ", fptr->fname);
            fptr = fptr->next;
        }

        printf("[%d] features", S[i]->numoffeat);

        printf("\n");
    }
}
#endif

int main(void) {
    int n;
    scanf("%d", &n);
    getchar();

    Station* SeoulMetro[n];

    char *namebuf;
    namebuf = (char *) calloc(sizeof(char), 11);
    for(int i = 0; i < n; i++) {
        namebuf = (char *) calloc(sizeof(char), 11);
        scanf("%s", namebuf);

        SeoulMetro[i] = SInit(namebuf);
        memset(namebuf, 0, sizeof(char) * 11);
    }
    free(namebuf);
    getchar();

    int r;
    scanf("%d", &r);
    getchar();

    int answer[r];
    int ansidx = 0;
    memset(answer, 0, sizeof(int)*r);

    char* longbuf;
    for(int i = 0; i < r; i++) { // 입력 횟수
        longbuf = (char *) calloc(sizeof(char), 999999);

        scanf("%[^\n]", longbuf);
        getchar();

        char *tok = strtok(longbuf, " ");

        if(mystrcmp(tok, "U", 1)) {
            tok = strtok(NULL, " "); // 역이름 나와야함

            for(int j = 0; j < n; j++) { // seoulmetro 역이름 탐색
                bool cmprslt = mystrcmp(tok, SeoulMetro[j]->sname, strlen(tok));

                if(cmprslt) {
                    tok = strtok(NULL, ","); // 기능 나와야함

                    SFeatAddFirst(SeoulMetro[j], tok);
                    tok = strtok(NULL, ",");

                    while(tok != NULL) {
                        SFeatAddNext(SeoulMetro[j], tok);
                        tok = strtok(NULL, ",");
                    }
                    /*** 어떤 역의 feature를 입력하는것은, 이어쓰는것이 아닌 무조건 처음부터 다시 ***/

                    break;
                }
            }
        }
        else if(mystrcmp(tok, "G", 1)) {
            tok = strtok(NULL, ","); // 기능명 나와야함

            bool barr[9][n]; // row : 기능, column : 각 역
            memset(barr, false, sizeof(bool) * 9 * n);
            int bidx = 0; // barr row

            while(tok != NULL) { // 찾고있는 기능 char* 하나씩 주어짐
                for(int j = 0; j < n; j++) { // seoulmetro 탐색
                    if(SFeatSearch(SeoulMetro[j], tok)) {
                        barr[bidx][j] = true;
                    }
                }
                tok = strtok(NULL, ",");
                bidx++;
            }

            int anstmp = 0;

            for(int j = 0; j < n; j++) { // barr column 탐색 - 각 역이 모든 기능을 가지고있는지
                bool tmp = true;

                for(int k = 0; k < bidx; k++) { // 한 역의 기능들 탐색
                    if(!barr[k][j]) {
                        tmp = false;
                        break;
                    }
                }

                if(tmp) {
                    anstmp++;
                }
            }
            answer[ansidx++] = anstmp;
        }
#if DEBUG
        else if((mystrcmp(tok, "S", 1))) { // for debug
            Dshow(SeoulMetro, n);
        }
#endif
        free(longbuf);
    }

    for(int i=0; i<ansidx; i++){
        printf("%d\n", answer[i]);
    }

    return 0;

}