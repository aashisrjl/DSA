//Insertion Sort
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int i,j,s,temp,a[20];
	printf("Enter total elements:");
	scanf("%d",&s);
	printf("Enter %d elements:",s);
	for(i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<s;i++)
	{
		temp=a[i];
		j=i-1;
		while((temp<a[j])&&(j>=0))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
	printf("Sorted elements are:");
	for(i=0;i<s;i++)
	printf("%d\t",a[i]);
	return 0;
}
