#include <stdio.h>
#include <stdlib.h>

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
