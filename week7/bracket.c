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
        printf("Stack overflow!");
        exit(1);
    }
    s.item[++s.top]=data;
    printf("%c is pushed to the Stack.\n",s.item[s.top]);
}

void pop(){
    if(s.top<0){
        printf("Stack underflow!");
        exit(1);
    }
    printf("%c is popped from the Stack.\n",s.item[s.top]);
    s.top--;
}

void checkBrackets(char st[]){
    int i=0;
    s.top=-1;
    while(st[i]!='\0'){
        if(st[i]=='[' || st[i]=='{' || st[i]=='(')
                push(st[i]);
        else if((st[i]==']' && s.item[s.top]=='[' )|| (st[i]=='}' && s.item[s.top]=='{')|| (st[i]==')'&& s.item[s.top]=='(')){
                pop();
        }
        i++;
    }
    if(s.top==-1){
        printf("Matching Parenthesis");
    }
    else
         printf("Not Matching Parenthesis");
}

int main(){
    char s[100];
    printf("\nEnter a string: ");
    scanf("%s",s);
    checkBrackets(s);
    return 0;
}
