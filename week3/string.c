#include<stdio.h>

int length(char s[]){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}
void concatenate(char s[],char s1[]){
    int l=length(s);
    int i=0;
    while(s1[i]!='\0'){
        s[l]=s1[i];
        i++;
        l++;
    }
    s[l]=='\0';
}
int compare(char s[],char s1[]){
    int i=0;
    while(s[i]!='\0'&&s1[i]!='\0'){
        if(s[i]!=s1[i])
            return (int)(s[i]-s1[i]);
        i++;
    }
    return (int)(s[i]-s1[i]);
}
void insert(char s[],char s1[],int index){
    int len_s=length(s);
    int len_s1=length(s1);
    s[length(s)+length(s1)+1]='\0';
    for (int i = len_s; i >= index; i--) {
    s[i + len_s1] = s[i];
    }
    for(int i=0;i<length(s1);i++){
        s[index+i]=s1[i];
    }
}
void del(char s[],char s1[]){
    int i=0,k=1,pos;
    while(s[i]!='\0'){
        k=1;
        for(int j=0;j<length(s1);j++){
            if(s[i+j]!=s1[j]){
                k=0;
                pos=0;
                break;
            }
            else{
                pos=i+j;
            }
        }
        if(k==1){
            int k1;
            pos=pos-length(s1)+1;
            for(k1=pos;k1<length(s)-length(s1);k1++)
                s[k1]=s[k1+length(s1)];
            s[k1]='\0';
        }
        i++;
    }
}
int main(){
    int n;
    char s[100];
    printf("Enter the string: ");
    scanf("%s",s);

    printf("Enter your choice:\n1. Length\n2. Concatenate\n3. Compare\n4. Insert\n5. Delete");
    int choice;
    scanf("%d",&choice);

    switch(choice){
        case 1: {
            printf("The length of the string is %d",length(s));
            break ;
        }
        case 2: {
            printf("Enter the string to concatenate: ");
            char s1[100];
            scanf("%s",s1);
            concatenate(s,s1);
            printf("The string after concatenation is %s",s);
            break;
        }
        case 3: {
            printf("Enter the string to compare: ");
            char s1[100];
            scanf("%s",s1);
            int res=compare(s,s1);
            if(res>0)
                printf("The first string is larger.");
            else if(res<0)
                printf("The first string is smaller.");
            else
                printf("Both string are same.");
            break;
        }
        case 4: {
            printf("Enter the string to insert: ");
            char s1[100];
            scanf("%s",s1);
            int index;
            printf("Enter the index to insert sub-string");
            scanf("%d",&index);
            insert(s,s1,index);
            printf("The string after insertion is %s",s);
            break;
        }
        case 5: {
            printf("Enter the string to delete: ");
            char s1[100];
            scanf("%s",s1);
            del(s,s1);
            printf("The string after deletion is %s",s);
            break;
        }
        default:
            printf("Invalid Choice!!!");
    }


    return 0;
}
