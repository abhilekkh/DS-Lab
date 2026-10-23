#include<stdio.h>

int main(){
    int a[10],n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter Array Elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int *ptr;
    ptr=a;
    printf("\nIncrementing Elements.....");
    for(int i=0;i<n;i++)
        *(ptr+i)+=1;
    printf("\nDisplaying Elements: ");
    for(int i=0;i<n;i++)
        printf("%d ",*(ptr+i));

    return 0;
}
