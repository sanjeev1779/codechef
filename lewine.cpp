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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int test_cases,m,n,i,j;
    S(test_cases);
    int maxm;
    int cap[52],val[52];
    while(test_cases--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
            S(cap[i]); S(val[i]);
        }

        int dp[5010];
        dp[0]=0;
        for(i=1;i<=n;i++)
        {
            // find maxm dp[w]= max( dp[w-w[i]]+val[i])
            maxm=0;
            // find maxm to fill i values
            for(j=1;j<=m;j++)
            {
                if(cap[j]<=i)
                {
                    maxm= max(dp[i-cap[j]] + val[j], maxm);
                }
            }
            dp[i]=maxm;
        }
        printf("%d\n",dp[n]);
    }
return 0;
}
