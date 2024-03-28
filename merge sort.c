//Merge Sort
#include<stdio.h>
#include<conio.h>
#define MAX 100
void merge(int L[],int R[],int A[],int nL,int nR)
{
	int i,j,k;
	i=j=k=0;
	while(i<nL && j<nR)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<nL)
	{
		A[k]=L[i];
		i++;
		k++;
	}
	while(j<nR)
	{
		A[k]=R[j];
		j++;
		k++;		
	}
}
void mergesort(int A[],int n)
{
	int i,mid;
	if(n<2)
	return;
	mid=n/2;
	int left[mid],right[n-mid];
	for(i=0;i<=(mid-1);i++)
	{
		left[i]=A[i];
	}
	for(i=mid;i<=(n-1);i++)
	{
		right[i-mid]=A[i];
	}
	mergesort(left,mid);
	mergesort(right,(n-mid));
	merge(left,right,A,mid,(n-mid));
}
int main()
{
	int merge[MAX],i,n;
	printf("Enter total no. of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&merge[i]);
	}
	mergesort(merge,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",merge[i]);
	}
	return 0;
}
