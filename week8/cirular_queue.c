#include<stdio.h>
#define MAX 5

typedef struct Queue{
   int front,rear;
    int item[MAX];
}Q;

void initializeQ(Q *q){
    q->front=0;
    q->rear=0;
}

int isEmpty(Q *q){
    return q->front==q->rear;
}
int isFull(Q *q){
    return (q->rear+1)%MAX==q->front;
}

void enqueue(Q *q, int value){
    if(isFull(q)){
        printf("\nCircular Queue is Full!");
        return;
    }
    q->item[q->rear]=value;
    q->rear=(q->rear+1)%MAX;
    printf("\n%d enqueued to the circular queue",value);
}

void dequeue(Q *q){
    if(isEmpty(q)){
        printf("\nCircular Queue is Empty!");
        return;
    }
    printf("Dequeued %d.",q->item[q->front]);
    q->front=(q->front+1)%MAX;
}

void peek(Q *q){
    if(isEmpty(q)){
        printf("\nCircular Queue is Empty!");
        return;
    }
    printf("%d is the front.",q->item[q->front]);
}

void bottom(Q *q){
    if(isEmpty(q)){
        printf("\nCircular Queue is Empty!");
        return;
    }
    printf("%d is the rear.",q->item[q->rear-1]);
}

void display(Q *q){
    int i=q->front;
    while(i!=q->rear){
        printf("%d ",q->item[i]);
        i=(i+1)%MAX;
    }
}

int main(){
    Q q;
    initializeQ(&q);
    int choice, value;
    while (1) {
    printf("\n\n--- Queue Menu ---\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Bottom\n5. Display\n6.Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        enqueue(&q, value);
    break;
    case 2:
        dequeue(&q);
        break;
    case 3:
        peek(&q);
    break;
    case 4:
        bottom(&q);
        break;
    case 5:
        display(&q);
        break;
    case 6:
        printf("Exiting...");
        return 0;
    default:
    printf("Invalid choice.\n"); } }

    return 0;
}
