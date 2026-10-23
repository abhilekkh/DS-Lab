#include<stdio.h>
void main(){
 int n,a[100];

 printf("Enter the number of elements: ");
 scanf("%d",&n);

printf("Enter the elements of array: ");
 for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
 }

 int choice;
 printf("Choose from the following methods to sort your array.\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n");
 scanf("%d",&choice);


 switch(choice){
 case 1:
     for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
 }

 printf("The array sorted using Bubble Sort: ");
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
 }
 break;

 case 2:
     int min_index;
     for(int i=0;i<n-1;i++){
        min_index=i;
    for(int j=i+1;j<n;j++){
        if(a[min_index]>a[j]){
            min_index=j;
        }
    }
    int temp=a[min_index];
    a[min_index]=a[i];
    a[i]=temp;
 }

 printf("The array sorted using Selection Sort: ");
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
 }
    break;
 case 3:
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
     printf("The array sorted using Insertion Sort: ");
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
 }
    break;
 default:
    printf("Invalid Choice!");
 }
}
