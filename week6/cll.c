#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node* createNode(int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("\nMemory Allocation failed.");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    printf("\nNewNode Created.");
    return newNode;
}



void insertEnd(Node **first, Node**last, int data){
    Node * newNode=createNode(data);
    if(*first==NULL){
        *first=newNode;
        (*first)->next=*first;
        (*last)=*first;
        printf("\nFilled in Head.");
        return;
    }
    (*last)->next=newNode;
    newNode->next=*first;
    *last=newNode;
    printf("\nLinked List after End Insertion: \n");
    display(*first,*last);
}

void delEnd(Node **last,Node **head){
    if(*head==NULL && *last==NULL ){
        printf("List is Empty");
    }

    else if (*head == *last) {
        printf("\nLast Node %d is deleted.", (*last)->data);
        free(*last);
        *head = NULL;
        *last = NULL;
        printf("\nLinked List is now empty.\n");
        return;
    }
    else{
    Node* temp=*head;
    while(temp->next!=*last ){
        temp=temp->next;
    }
    printf("\nLast Node %d is deleted.",(*last)->data);
    *last=temp;
    (*last)->next=*head;
    printf("\nLinked List after End Deletion: \n");
    display(*head,*last);
    temp=NULL;
    free(temp);
}
}
void delFront(Node **last,Node **head){
    if(*head==NULL && *last==NULL ){
        printf("List is Empty");
    }
    else if (*head == *last) {
        printf("\First Node %d is deleted.", (*head)->data);
        free(*last);
        *head = NULL;
        *last = NULL;
        printf("\nLinked List is now empty.\n");
        return;
    }
    else{
    Node* temp=*head;
    printf("\nFirst Node %d is deleted.",temp->data);
    *head=temp->next;
    (*last)->next=*head;
    printf("\nLinked List after Front Deletion: \n");
    display(*head,*last);
    temp=NULL;
    free(temp);
}}

void display(Node * head,Node * last){
    Node* temp=head;
    while(temp!=last){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
        temp=temp->next;
}

int main(){
    Node *first;
    Node *last;
    first=(Node*)malloc(sizeof(Node));
    last=(Node*)malloc(sizeof(Node));
    first=NULL;
    last=NULL;
    int ch;
    while(1){
    printf("\n=====Menu=====");
    printf("\n1. InsertEnd \n2. Delete End \n3. Delete Front \n4. Display \n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        int data;
        printf("\nEnter the data: ");
        scanf("%d",&data);
        insertEnd(&first,&last,data);
        break;
    case 2:
        delEnd(&last,&first);
        break;
    case 3:
        delFront(&last,&first);
        break;
    case 4:
        display(first,last);
        break;
    case 5:
        printf("\nExiting....");
        return 0;
        break;
    default:
        printf("\nInvalid Choice! Try Again....");
    }
}
return 0;
}
