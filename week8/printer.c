#include<stdio.h>
#define MAX 100

typedef struct Task{
 int docId;
 char name[50];
}Task;

typedef struct Queue{
    int front,rear;
    Task item[MAX];
}Queue;

void accept(Task *t){
    printf("\nEnter the task name: ");
    scanf("%s",t->name);
    printf("\nEnter document ID: ");
    scanf("%d",&t->docId);
}
void initializeQueue(Queue *q){
    q->front=-1;
    q->rear=-1;
}

int isFull(Queue *q){
    return q->rear==MAX - 1;
}
int isEmpty(Queue *q){
    return q->front==-1;
}

void enqueue(Queue *q, Task *t){
    if(isFull(q)){
        printf("\nQueue is Full");
        return;
    }
    if(isEmpty(q))q->front=0;
    q->item[++q->rear]=*t;
    printf("\nTask %s with Document ID %d is enqueued.",t->name,t->docId);
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.");
        return;
    }
    printf("\nPrintnig...\n");
    printf("\nTask Name:%s\nDocument ID=%d",(q->item[q->front]).name,(q->item[q->front]).docId);
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front++;
}

int main(){
    int n;
    printf("\nEnter the number of print jobs: ");
    scanf("%d",&n);
    Task t[n];
    printf("\nEnter the print job details: ");
    for(int i=0;i<n;i++){
        printf("\nPrint job %d",i+1);
        accept(&t[i]);
    }

    Queue q;
    initializeQueue(&q);

    printf("\nEnqueuing the Tasks: ");
    for(int i=0;i<n;i++){
        enqueue(&q,&t[i]);
    }

    printf("\nDequeuing the Tasks: ");
    for(int i=0;i<n;i++){
        dequeue(&q);
    }
    return 0;
}
