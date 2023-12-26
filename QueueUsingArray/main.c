



#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int * Q;
};
struct Queue q;

void createQueue(struct Queue * qT);
void displayQueue(struct Queue  qT);

void enqueue(struct Queue * qT,int data);
int isFull(struct Queue * qT);

int dequeue(struct Queue * qT);
int isEmpty(struct Queue * qT);

int main(int argc, const char * argv[]) {
    createQueue(&q);
    enqueue(&q,2);
    enqueue(&q,4);
    enqueue(&q,6);
    enqueue(&q,8);
    enqueue(&q,10);
    enqueue(&q,12);
    displayQueue(q);
    int data = dequeue(&q);
    printf("Removed element is  = %d\n",data);
    displayQueue(q);
    return 0;
}
void createQueue(struct Queue * qT){
    printf("Enter size of queue\n");
    scanf("%d",&qT->size);
    qT->front = -1;
    qT->rear = -1;
    qT->Q = (int *)malloc(qT->size * sizeof(int));
}

void displayQueue(struct Queue  qT){
    for (int i= qT.front+1; i<= qT.rear; i++) {
        printf("Q[%d] = %d\n",i,qT.Q[i]);
    }
}

void enqueue(struct Queue * qT,int data){
    if(isFull(qT)){
        printf("Queue is full\n");
        return ;
    }
    qT->rear ++;
    qT->Q[qT->rear] = data;
}

int isFull(struct Queue * qT){
    return qT->rear == (qT->size-1);
}

int dequeue(struct Queue * qT){
    if(isEmpty(qT)){
        printf("Queue is Empty\n");
        return -1;
    }
    qT->front ++;
    return  qT->Q[qT->front];
}

int isEmpty(struct Queue * qT){
    return qT->rear == (qT->front);
}
