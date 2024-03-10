#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int Data;

typedef struct _Node {
    Data d;
    struct _Node *prev;
    struct _Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int numofdata;
} Deque;

void DequeInit(Deque *D) {
    D->head = (Node *) malloc(sizeof(Node));
    D->tail = (Node *) malloc(sizeof(Node));

    D->head->prev = NULL;
    D->tail->next = NULL;

    D->head->next = D->tail;
    D->tail->prev = D->head;

    D->numofdata = 0;
}

unsigned int DCount(Deque *D) {
    return D->numofdata;
}

bool DIsEmpty(Deque *D) {
    if(D->numofdata == 0) {
        return true;
    }
    else {
        return false;
    }
}

void DPushFront(Deque *D, Data d) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    newNode->d = d;

    newNode->next = D->head->next;
    newNode->next->prev = newNode;

    newNode->prev = D->head;
    D->head->next = newNode;

    D->numofdata++;
}

void DPushRear(Deque *D, Data d) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    newNode->d = d;

    newNode->prev = D->tail->prev;
    newNode->prev->next = newNode;

    newNode->next = D->tail;
    D->tail->prev = newNode;

    D->numofdata++;
}

Data DPeekFront(Deque *D) {
    if(DIsEmpty(D) == false) {
        return D->head->next->d;
    }
    else {
        //printf("nothing to peek!\n");
        return -1;
    }
}

Data DPeekRear(Deque *D) {
    if(DIsEmpty(D) == false) {
        return D->tail->prev->d;
    }
    else {
        //printf("nothing to peek!\n");
        return -1;
    }
}

Data DPopFront(Deque *D) {
    if(DIsEmpty(D) == false) {
        Data ret = DPeekFront(D);

        Node *cur = D->head->next;
        Node *left = cur->prev;
        Node *right = cur->next;

        left->next = right;
        right->prev = left;

        free(cur);

        D->numofdata--;

        return ret;
    }
    else {
        //printf("nothing to pop!\n");
        return -1;
    }

}

Data DPopRear(Deque *D) {
    if(DIsEmpty(D) == false) {
        Data ret = DPeekRear(D);

        Node *cur = D->tail->prev;
        Node *left = cur->prev;
        Node *right = cur->next;

        left->next = right;
        right->prev = left;

        free(cur);

        D->numofdata--;

        return ret;
    }
    else {
        //printf("nothing to pop!\n");
        return -1;
    }
}

// for debug
void DShow(Deque *D) {
    if(DIsEmpty(D) == false){
        int nod = D->numofdata;
        Node *cur;

        cur = D->head->next;
        printf("(head) ");
        for(int i=0; i<nod; i++){
            printf("%d ", cur->d);
            cur = cur->next;
        }
        printf("(tail)\n");

        cur = D->tail->prev;
        printf("(tail) ");
        for(int i=0; i<nod; i++){
            printf("%d ", cur->d);
            cur = cur->prev;
        }
        printf("(head)\n");
    }
    else{
        printf("nothing to show!\n");
    }
}