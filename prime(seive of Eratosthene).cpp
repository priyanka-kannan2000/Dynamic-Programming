#include<stdio.h>
#include<math.h>
main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n-2];
	for(i=0;i<n-1;i++)
	{
		a[i]=i+2;
	}
	for(i=a[i];i<sqrt(n);i++)
	{
		if(a[i]!=0)
		{
			for(j=i+a[i];j<n-1;j=j+a[i])
			{
				a[j]=0;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]!=0)
		{
			printf("%d ",a[i]);
		}
	}
}
