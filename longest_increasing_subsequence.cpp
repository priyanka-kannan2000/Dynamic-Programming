#include<stdio.h>
int subseq(int max,int index,int a[],int dp[])
{
	if(max==0)
		return 0;
	if(dp[index]==max)
	{
		subseq(max-1,index-1,a,dp);
		printf("%d ",a[index]);
	}
	else
		subseq(max,index-1,a,dp);
}
main()
{
	int n,i,j,max=1;
	scanf("%d",&n);
	int a[n];
	int dp[n-1];
	for(i=0;i<n;i++)
	{
		scanf("%d ",&a[i]);
		dp[i]=1;
	}
	
	j=0;
	i=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				if(dp[j]+1>dp[i])
				{
					dp[i]=dp[j]+1;
				}
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",dp[i]);
	}
	printf("\n");
	int index;
	for(i=0;i<n;i++)
	{
		if(max<dp[i])
		{
			max=dp[i];
			index=i;
		}
	}
	
/*	while(max>0)
	{
		if(dp[index]==max)
		{
			printf("%d ",a[index]);
			max--;
			index--;
		}
		else
		{
			index--;
		}
	}*/
	subseq(max,index,a,dp);	

}
