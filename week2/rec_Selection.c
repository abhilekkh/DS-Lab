#include<stdio.h>
#include<stdlib.h>

void rec_Selection(int *arr,int n){
    if(n<=0)
        return;

    int max=0;
    for(int j=1;j<=n;j++)
    {
        if(*(arr+j)>*(arr+max))
            max=j;
    }
    int temp=*(arr+max);
    *(arr+max)=*(arr+n);
    *(arr+n)=temp;

    rec_Selection(arr,n-1);

}

int main(){
    int *arr,n;

    printf("\nEnter number of elements: ");
    scanf("%d",&n);

    arr=(int*)malloc(n*sizeof(int));

    if(arr==NULL){
        printf("\nMemory not Allocated");
        return 1;
    }

    printf("\nEnter Array Elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",(arr+i));

    printf("\nSorting using recursive Selection sort.....");
    rec_Selection(arr,n-1);

    printf("\nSorted Array: ");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));

        free(arr);

    return 0;
}
