#include<stdio.h>
#include<stdlib.h>

int small(int* arr,int n){
    int small=arr[0];
    for(int i=0;i<n;i++){
        if(small>arr[i])
            small=arr[i];
    }
    return small;
}

int main(){
    int *arr;
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    arr=(int *)malloc(n*sizeof(int));

    if(arr==NULL){
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Enter Array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    printf("The smallest element in the array is %d", small(arr,n));
    free(arr);
    return 0;

}
