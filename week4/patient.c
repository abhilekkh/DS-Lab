#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    int priority;
} Patient;

typedef struct PatientNode {
    Patient data;
    struct PatientNode* next;
} PatientNode;

typedef struct {
    PatientNode* front;
    PatientNode* rear;
} PatientQueue;

void initPatientQueue(PatientQueue* pq) {
    pq->front = pq->rear = NULL;
}

void enqueuePatient(PatientQueue* pq, char* name, int age, int priority) {
    PatientNode* newNode = (PatientNode*)malloc(sizeof(PatientNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newNode->data.name, name);
    newNode->data.age = age;
    newNode->data.priority = priority;
    newNode->next = NULL;

    if (pq->rear == NULL) {
        pq->front = pq->rear = newNode;
    } else {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
    printf("Patient %s added to the queue.\n", name);
}

void dequeuePatient(PatientQueue* pq) {
    if (pq->front == NULL) {
        printf("Patient Queue is empty.\n");
        return;
    }
    PatientNode* temp = pq->front;
    printf("\n[Serving Patient]: %s (Age: %d, Priority: %d)\n",
           temp->data.name, temp->data.age, temp->data.priority);

    pq->front = pq->front->next;

    if (pq->front == NULL) {
        pq->rear = NULL;
    }
    free(temp);
}

void displayPatientQueue(PatientQueue* pq) {
    if (pq->front == NULL) {
        printf("\nPatient Queue is empty.\n");
        return;
    }
    PatientNode* temp = pq->front;
    printf("\n--- Current Patient Queue (Front to Rear) ---\n");
    while (temp != NULL) {
        printf("Name: %s | Age: %d | Priority: %d\n",
               temp->data.name, temp->data.age, temp->data.priority);
        temp = temp->next;
    }
    printf("-------------------------------------------\n");
}

int main() {
    PatientQueue pq;
    initPatientQueue(&pq);

    printf("=== QUEUE OF PATIENT STRUCTURES DEMO ===\n");
    enqueuePatient(&pq, "Alice", 34, 2);
    enqueuePatient(&pq, "Bob", 52, 1);
    enqueuePatient(&pq, "Charlie", 23, 3);

    displayPatientQueue(&pq);

    dequeuePatient(&pq);

    displayPatientQueue(&pq);

    return 0;
}
