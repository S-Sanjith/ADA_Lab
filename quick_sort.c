#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int array[],int,int);
void quicksort(int array[25],int first,int last)
{
    int pi;
    if(first<last)
    {
        pi=partition(array,first,last);
        quicksort(array,first,pi-1);
        quicksort(array,pi+1,last);
    }
}

int partition(int array[],int first,int last){
    int i,j,temp,pivot = array[first];
    i=first+1;
    j=last;
    printf("Pivot = %d\n",pivot);
    while(i<=j){
        while(array[i]<=pivot)
            i++;
        while(array[j]>pivot)
            j--;
        if(i<j){
            printf("Swapping %d and %d \n",array[i],array[j]);
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    printf("Swapping %d and %d \n",array[j],pivot);
    temp=array[first];
    array[first]=array[j];
    array[j]=temp;
    return j;
}

int main(){
    int i,n,array[1000];
    clock_t initial,final;
    printf("Total number of elements  : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        array[i]=rand();
        //printf("%d ", array[i]);
    }
    printf("\n");
    initial=clock();
    quicksort(array,0,n-1);
    final=clock();

    printf("Sorted Order : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\nTotal time taken to Sort %d elements : %e\n",n,difftime(final,initial)/CLOCKS_PER_SEC);
    return 0;
}
