#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void del() {
    int i, j, x;
    for(i = 0; i < 1000; i++) {
        for(j = 0; j < 1000; j++) {
            x = 1000;
        }
    }
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[10000];
	int i,j,k;
	i=i1;
	j=i2;
	k=0;

	while(i<=j1 && j<=j2)
	{
		if(a[i]<a[j]) {
			temp[k++]=a[i++];
			del();
		}
		else {
			temp[k++]=a[j++];
			del();
        }
	}

	while(i<=j1) {
		temp[k++]=a[i++];
		del();
	}

	while(j<=j2) {
		temp[k++]=a[j++];
		del();
    }

	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}

void mergesort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		//left recursion
		mergesort(a,mid+1,j);	//right recursion
		merge(a,i,mid,mid+1,j);	//merging
	}
}

int main()
{
	int a[1000],n,i;
    clock_t initial,final;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter array elements:");

	for(i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d ", a[i]);
    }
    printf("\n");
    initial=clock();
	mergesort(a,0,n-1);
    final=clock();

	printf("\nSorted array\n");
	for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nTotal time taken to Sort %d elements : %e\n",n,difftime(final,initial)/CLOCKS_PER_SEC);
	return 0;
	}
