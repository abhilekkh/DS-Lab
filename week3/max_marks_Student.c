#include<stdio.h>

typedef struct Student Student;
struct Student{
    char name[50];
    int rollno;
    float marks;
};

void read(Student *s,int n){
    for(int i=0;i<n;i++){
        printf("\nEnter Name: ");
        scanf("%s",(s+i)->name);
        printf("\nEnter Rollno.:");
        scanf("%d",&(s+i)->rollno);
        printf("\nEnter Marks: ");
        scanf(" %f",&(s+i)->marks);
    }
}

void display(Student s[],int n){
    for(int i=0;i<n;i++){
     printf("\nName: %s",s[i].name);
     printf("\nRollno.: %d",s[i].rollno);
     printf("\nMarks: %f", s[i].marks);
    }
}

void max(Student *s,int n){
    Student *max=s;
    for(int i=1;i<n;i++){
        if(max->marks<(s+i)->marks)
            max=(s+i);
    }
    printf("\nDisplaying Details of Student with Highest Marks....");
    printf("\nName: %s", (max)->name);
    printf("\nRoll no.: %d", (max)->rollno);
    printf("\nMarks: %0.2f", (max)->marks);
}

int main(){
    int n;
    printf("\nEnter number of students: ");
    scanf("%d",&n);
    Student s[n];
    read(s,n);
    display(s,n);
    max(s,n);
    return 0;
}
