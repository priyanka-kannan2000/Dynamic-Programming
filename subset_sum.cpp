#include<stdio.h>
main()
{
	int n,a[100],k,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	int dp[n][k+1];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k+1;j++)
		{
			if(j==0)
			{
				dp[i][j]=1;
			}
			else if(i==0)
			{
				if(j==a[0])
				dp[i][j]=1;
				else
				dp[i][j]=0;
			}
			else
			{
				if(a[i]>j)
				dp[i][j]=dp[i-1][j];
				else
				{
					dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<k+1;j++)
		{
			printf("%d",dp[i][j]);
		}
		printf("\n");
	}
	//finding the subset
	i=n-1;
	j=k;
	while(i!=0 && j!=0)
	{
		if(dp[i-1][j]==1)
		{
			i--;
		}
		else
		{
			printf("%d ",a[i]);	
			j=j-a[i];
			i--;
		}
	}
	if(j!=0)
	{
		printf("%d ",a[0]);
	}
	
}
