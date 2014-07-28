#include<stdio.h>
#include<string.h>
#include<iostream>
#define ll long long
using namespace std;

int arr[65];
ll dp[10001][65];
int n;
int gcd(int a,int b)
{
	if(b==0)
        return a;
	else
        return gcd(b,a%b);
}




ll calc(int curr_gcd,int pos)
{
	if(pos==n&&curr_gcd==1)
        return 1;

	else
     if(pos==n&&curr_gcd!=1)
        return 0;

    if(dp[curr_gcd][pos]!=-1)
        return dp[curr_gcd][pos];

	else
	{
		ll result=calc(gcd(curr_gcd,arr[pos]),pos+1)+calc(curr_gcd,pos+1);
		dp[curr_gcd][pos]=result;
		return result;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i,j;
		memset(dp,-1,sizeof(dp));

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
		ll ans=0;

		for(i=0;i<n;i++)
            ans+=calc(arr[i],i);

		printf("%lld\n",ans/2);
	}
	return 0;
}
