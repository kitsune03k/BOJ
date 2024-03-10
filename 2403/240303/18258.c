#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int Data;

typedef struct _Node {
    Data d;
    struct _Node *prev;
    struct _Node *next;
} Node;

typedef struct {
    Node *head; // dmy;
    Node *tail; // dmy;
    int numofdata;
} Queue;

void QueueInit(Queue *Q) {
    Q->head = (Node *) malloc(sizeof(Node));
    Q->tail = (Node *) malloc(sizeof(Node));

    Q->head->prev = NULL;
    Q->tail->next = NULL;

    // dummy node 사용하면 빼먹지말자!!
    Q->head->next = Q->tail;
    Q->tail->prev = Q->head;

    Q->numofdata = 0;
}

int QSize(Queue *Q) {
    return Q->numofdata;
}

bool QIsEmpty(Queue *Q) {
    if(QSize(Q) == 0) {
        return true;
    }
    else {
        return false;
    }
}

void QEnqueue(Queue *Q, Data x) {
    // 연결리스트 기반으로 구성하면, 최대 크기에 대한 제한이 없다!
    Node *newNode = (Node *) malloc(sizeof(Node));

    newNode->d = x;
    newNode->next = Q->tail;
    newNode->prev = Q->tail->prev;

    Q->tail->prev->next = newNode;
    Q->tail->prev = newNode;

    Q->numofdata++;
}

Data QPeek(Queue *Q) {
    if(QIsEmpty(Q) == false) {
        return Q->head->next->d;
    }
    else {
        //printf("nothing to peek!\n");
        return -1;
    }
}

Data QDequeue(Queue *Q) {
    if(QIsEmpty(Q) == false) {
        Data ret = QPeek(Q);

        Node *cur = Q->head->next;
        Node *left = Q->head;
        Node *right = Q->head->next->next;

        left->next = right;
        right->prev = left;

        free(cur);

        Q->numofdata--;

        return ret;
    }
    else {
        //printf("nothing to dequeue!\n");
        return -1;
    }

}

Data QPeekTail(Queue *Q) { // 표준 Queue 기능 아님!!
    if(QIsEmpty(Q) == false) {
        return Q->tail->prev->d;
    }
    else {
        //printf("nothing to peektail!\n");
        return -1;
    }
}

// for debug

void QShow(Queue *Q) {
    if(QIsEmpty(Q) == false) {
        Node *cur;

        cur = Q->head->next;
        printf("(head)");
        for(int i = 0; i < Q->numofdata; i++) {
            printf("%d", cur->d);

            if(i != Q->numofdata-1)
                printf(" -> ");


            cur = cur->next;
        }
        printf("(tail)\n");

        cur = Q->tail->prev;
        printf("(tail)");
        for(int i = 0; i < Q->numofdata; i++) {
            printf("%d", cur->d);

            if(i != Q->numofdata-1)
                printf(" -> ");

            cur = cur->prev;
        }
        printf("(head)\n");
        printf("size : %d\n", QSize(Q));
    }
    else {
        printf("nothing to show!");
    }
}

char *func[6] = {
        // enqueue, dequeue, size, isempty, peek, peektail
        "push", "pop", "size", "empty", "front", "back"

};

int whatsel() {
    int ret = -1;

    char buf[6] = {0,};
    scanf("%s", buf);
    getchar();

    for(int j = 0; j < 6; j++) {
        if(strcmp(buf, func[j]) == 0) {
            ret = j;
            break;
        }
    }

    return ret;
}

int main(void) {
    Queue *Q = (Queue *) malloc(sizeof(Queue));
    QueueInit(Q);

    int n;
    scanf("%d", &n);
    getchar();

    Data* ans = (Data*) malloc(sizeof(Data)*n);
    int ansidx = 0;

    int sel;
    for(int i = 0; i < n; i++) {
        sel = whatsel();

        switch(sel) {
            case 0: { // push (enqueue)
                Data d;
                scanf("%d", &d);
                getchar();

                QEnqueue(Q, d);
                break;
            }
            case 1: { // pop (dequeue)
                Data ret = QDequeue(Q);
                ans[ansidx++] = (int) ret;
                break;
            }
            case 2: { // size (size)
                int ret = QSize(Q);
                ans[ansidx++] = ret;
                break;
            }
            case 3: { // empty (isempty)
                bool ret = QIsEmpty(Q);
                ans[ansidx++] = (int) ret;
                break;
            }
            case 4: { // front (peek)
                Data ret = QPeek(Q);
                ans[ansidx++] = (int) ret;
                break;
            }
            case 5: { // back (peektail)
                Data ret = QPeekTail(Q);
                ans[ansidx++] = (int) ret;
                break;
            }
            default:
                printf("selection error!!\n");
        }

        //QShow(Q);
    }

    for(int i = 0; i < ansidx; i++) {
        printf("%d\n", ans[i]);
    }


    return 0;

}