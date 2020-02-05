#include<stdio.h>
#include<stdlib.h>
main()
{
	int **a,i,j,n=3;
	a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		     *(*(a+i)+j)=i+1;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d,%d\n",(*(a+i)+j),*(*(a+i)+j));
		}
	}
}
