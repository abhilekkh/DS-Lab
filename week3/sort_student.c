#include<stdio.h>

struct Student{
    char name[100];
    int rollno;
    char grade;
};

void read(struct Student *s){
    printf("\nEnter Name: ");
    scanf("%s",s->name);
    printf("\nEnter Rollno.:");
    scanf("%d",&s->rollno);
    printf("\nEnter Grade: ");
    scanf(" %c",&s->grade);
}

void display(struct Student s){
    printf("\nName: %s",s.name);
    printf("\nRollno.: %d",s.rollno);
    printf("\nGrade: %c", s.grade);
}

void sort(struct Student s[], int n){
    struct Student temp;
    for(int i=0;i<n-1;i++){
        {
            for(int j=i;j<n-i-1;j++){
                if(s[j].rollno>s[j+1].rollno){
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }
    }
}

int main(){
    int n;
    printf("\nEnter number of students: ");
    scanf("%d",&n);
    struct Student s[n];

    printf("\nEnter Student Details\n");
    for(int i=0;i<n;i++){
        printf("\nStudent %d\n",i+1);
        read(&s[i]);
    }

    printf("\nDisplaying Student Details.....\n");
    for(int i=0;i<n;i++){
        printf("\nStudent %d\n",i+1);
        display(s[i]);
    }


    printf("\nSorting Student Based on Roll Number.....\n");
        sort(s,n);

    printf("\nDisplaying Student Details after Sorting.....\n");
    for(int i=0;i<n;i++){
        printf("\nStudent %d\n",i+1);
        display(s[i]);
    }

    return 0;

}
