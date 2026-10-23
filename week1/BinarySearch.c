#include<stdio.h>

void main(){
 int n,a[100];

 printf("Enter the number of elements: ");
 scanf("%d",&n);

 printf("Enter the elements of sorted array: ");
 for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
 }

 printf("Enter the element to search: ");
 int key,f=0,l=0,u=n-1,index;
scanf("%d",&key);
 for(int i=0;i<n;i++){
    int mid=(l+u)/2;
    if(a[mid]>key)
        u=mid-1;
    else if(a[mid]<key)
        l=mid+1;
    else{
        f=1;
        index=mid;
    }
 }

if(f==1)
printf("\nThe element is present in the given array at index %d.\n", index);
else
printf("\nThe element was not found in the given array.\n");


}
