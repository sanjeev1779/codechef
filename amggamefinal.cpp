#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;
int a[62];
LL dp[10002][62];
int n;
int gcd(int a,int b)
{
	if(a%b==0)
        return b;
	else
        return gcd(b,a%b);
}
LL solve(int pos, int cur_gcd)
{
    LL x;
    if(pos==n && cur_gcd==1)
        return 1;
    if(pos==n && cur_gcd!=1)
        return 0;
    if(dp[cur_gcd][pos]!=-1)
        return dp[cur_gcd][pos];
    x= solve(pos+1, cur_gcd) + solve(pos+1, gcd(cur_gcd,a[pos]));
    dp[cur_gcd][pos]=x;
    return x;
}
main()
{
    int test_cases,i;
    scanf("%d",&test_cases);
   LL ans=0;
    while(test_cases--)
    {
        ans=0;
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i++)
                ans=ans+ solve(i,a[i]);
        printf("%lld\n",ans/2);
    }

return 0;
}
