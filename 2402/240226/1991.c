#include <stdio.h>
#include <stdlib.h>

#define PN printf("\n")

typedef struct _bTree{
    char c;
    struct _bTree * LNode;
    struct _bTree * RNode;
} Node;

Node* makeNode(char c){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->c = c;
    newNode->LNode = NULL;
    newNode->RNode = NULL;

    return newNode;
}


void makeLChild(Node* parent, Node* left){
    parent->LNode = left;
}

void makeRChild(Node* parent, Node* right){
    parent->RNode = right;
}

void preT(Node* root){ // 전위순회
    if(root){
        printf("%c", root->c);
        preT(root->LNode);
        preT(root->RNode);
    }
}

void inT(Node* root){ // 중위순회
    if(root){
        inT(root->LNode);
        printf("%c", root->c);
        inT(root->RNode);
    }
}

void postT(Node* root){ // 후위순회
    if(root){
        postT(root->LNode);
        postT(root->RNode);
        printf("%c", root->c);
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    getchar();

    Node* arr[N];
    for(int i=0; i<N; i++){
        arr[i] = makeNode((char)('A'+i));
    }

    char c1, c2, c3;
    for(int i=0; i<N; i++){
        scanf("%c %c %c", &c1, &c2, &c3);
        getchar();

        if(c2 != '.') {
            makeLChild(arr[c1 - 'A'], arr[c2 - 'A']);
        }

        if(c3 != '.') {
            makeRChild(arr[c1 - 'A'], arr[c3 - 'A']);
        }
    }

    preT(arr[0]);
    PN;
    inT(arr[0]);
    PN;
    postT(arr[0]);


    return 0;

}