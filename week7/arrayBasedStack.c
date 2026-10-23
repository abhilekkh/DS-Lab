#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100
typedef struct Stack{
    char item[MAX_SIZE];
    int top;
}Stack;

Stack s;

void push(char data){
    if(s.top>MAX_SIZE){
        printf("Stack Overflow");
        exit(1);
    }
    s.item[++s.top]=data;
    printf("%c is pushed to the Stack.\n",data);
}

void pop(){
    if(s.top<0){
        printf("Stack Underflow");
        exit(1);
    }
    printf("%c is popped from the Stack.\n",s.item[s.top]);
    s.top--;
}

char peek(){
    if(s.top<0){
        printf("Stack is empty");
        exit(1);
    }
    return s.item[s.top];
}

bool isEmpty(){
    if(s.top==-1)
        return true;
    return false;
}

void isFull(){
     if(s.top==MAX_SIZE)
        printf("Stack is Empty");
}


void isPalindrome(char st[]){
    int length=0;
    while(st[length]!='\0'){
        length++;
    }
    s.top=-1;
    for(int i=0; i<length/2; i++){
        push(st[i]);
    }

    // Determine where to start comparing for the second half
    int start = (length % 2 == 0) ? length / 2 : (length / 2) + 1;

    // Compare and pop matching characters
    for(int i=start; i<length; i++){
        if(s.item[s.top]==st[i])
            pop();
    }

    if(isEmpty())
        printf("String is Palindrome\n");
    else{
        printf("String is not Palindrome\n");
    }
}
}

int main(){
    char s[100];
    printf("\nEnter a string: ");
    scanf("%s",s);
    isPalindrome(s);
    return 0;
}
