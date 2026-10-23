#include<stdio.h>

void main(){
int n,a[100];
printf("Enter number of elements: ");
scanf("%d",&n);

for(int i=0;i<n;i++){
    printf("\nEnter element %d: ", (i+1));
    scanf("%d",&a[i]);
}

printf("\nEnter element to search: ");
int key,f=0,index;
scanf("%d",&key);

for(int i=0;i<n;i++){
    if(a[i]==key){
            f=1;
            index=i;
    }
}
if(f==1)
printf("\nThe element is present in the given array at index %d.\n", index);
else
printf("\nThe element was not found in the given array.\n");

}
