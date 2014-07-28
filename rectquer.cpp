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
int dp[305][305][12];
main()
{
    int N,i,j,k,Q,x1,y1,x2,y2,dis;
    S(N);
    int x;
    int cnt=0;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            {
                S(x);
                {
                    //dp[i][j][x]++;
                    for(k=1;k<=10;k++)
                    {
                        if(k==x)
                            dp[i][j][x]= dp[i][j-1][x]+ dp[i-1][j][x]- dp[i-1][j-1][x]+1;
                        else
                             dp[i][j][k]= dp[i][j-1][k]+ dp[i-1][j][k]- dp[i-1][j-1][k];
                    }
                }
            }
    }
   /* for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            for(k=1;k<=10;k++)
            {
                cout<<dp[i][j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }*/
    S(Q);
    while(Q--)
    {
        cnt=0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(i=1;i<=10;i++)
        {
            dis= dp[x1-1][y1-1][i]+ dp[x2][y2][i] - dp[x1-1][y2][i] - dp[x2][y1-1][i];
           // cout<<dis<<"  ";
            if(dis>0)
                cnt++;
        }
        printf("%d\n",cnt);
    }
return 0;
}
