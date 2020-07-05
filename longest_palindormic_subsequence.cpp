#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	return (a>b)?a:b;
}
main()
{
	char a[200];
	int i,j,k=1;
	scanf("%s",a);
	int n=strlen(a);
	int dp[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				dp[i][j]=1;
			else
				dp[i][j]=0;
		}
	}
	while(1)
	{
		i=0;
		j=k;
		if(i==0 && j==n)
			break;
		while(j<n)
		{
			if(a[i]!=a[j])
				dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
			else
				dp[i][j]=dp[i+1][j-1]+2;
			j++;
			i++;
		}
		k++;
	}
	//printing the longest substring
	char ans[200];
	k=0,i=0,j=n-1;
	while(dp[i][j]!=0)
	{
		if(a[i]!=a[j])
		{
			if(dp[i][j-1]>=dp[i+1][j])
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		else
		{
			ans[k]=a[i];
			k++;
			i++;
			j--;
		}
	}
	//copying the other side of the palindrome
	if(dp[0][n-1]%2==0)
	{
		int t=k-1;
		for(i=t;i>=0;i--)
		{
			ans[k]=ans[i];
			k++;
		}
	}
	else
	{
		int t=k-2;
		while(t>=0)
		{
			ans[k]=ans[t];
			t--;
			k++;
		}
	}
	ans[k]='\0';
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",dp[i][j]);
		}
		printf("\n");
	}
	printf("%s",ans);
}
