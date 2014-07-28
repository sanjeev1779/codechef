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
int dp[102][100005];
main()
{
    int N,Q,s,K,x,i,j,k;
    S(N); S(Q);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(i=0;i<N;i++)
    {
        S(x);
        for(j=i;j>=0;j--) // for num of elements 0 to j
        {
            for(k=0;k<=1000*i;k++)
            {
                if(dp[j][k])
                    dp[j+1][k+x]=1;
            }
        }
    }
    while(Q--)
    {
        S(s);S(k); // sum S using K number of coins
        if(dp[k][s])
            printf("YES\n");
        else
            printf("NO\n");
    }
return 0;
}
