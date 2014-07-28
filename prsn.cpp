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
int maxm_val=10000000;
using namespace std;

inline int fastRead_int()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};

main()
{
    int N,M,i,j,k,x;
    S(N);
    int Z;
    int minm;
    int arr[105];
    int dp[105][105];
    while(N--)
    {
        //S(M);
        //S(Z);
        M=fastRead_int();
        Z= fastRead_int();
        memset(dp,0,sizeof(dp));
        arr[0]=0;
        for(i=1;i<=Z;i++)
        {
            //S(arr[i]);
           arr[i]= fastRead_int();
        }
        arr[Z+1]=M+1;

        for(i=2;i<=Z+1;i++) // we hv to delete  Z monkeys
        {
            for(j=0;j<=Z+1-i;j++)
            {
                //find the minm cost from i to j
                minm= maxm_val;
                for(k=j+1;k<i+j;k++)
                {
                    // dp[][]=
                    minm= min( minm, dp[j][k]+dp[k][i+j]+arr[i+j]-arr[j]-2);
                }
                dp[j][i+j]=minm; // minm cost for paying from ith to jth cell
              // cout<<"hi "<<i<<" "<<j+i<<" "<<dp[i][j+i]<<endl;
            }
            //cout<<"next\n";
        }
        //cout<<"dp matrix\n"<<endl;
       /* for(i=0;i<=Z+1;i++)
        {
            for(j=0;j<=Z+1;j++)
            {
                printf("%d ",dp[i][j]);
            }
            cout<<endl;
        }*/
        //cout<<"ans= ";
        cout<<dp[0][Z+1]<<endl;
    }
return 0;
}
