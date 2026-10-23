#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to the queue.\n", val);
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("%d dequeued from the queue.\n", temp->data);

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue (Front to Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    printf("=== BASIC LINKED LIST QUEUE DEMO ===\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q);

    dequeue(&q);
    displayQueue(&q);

    return 0;
}
