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
int N;
int i,j;

int solve(int a[],int sum,int cur_sum,int idx)
{
    int dp[1002][1002];
    for(i=0;i<1002;i++)
    {
        dp[0][i]=0;
        dp[i][0]=0;
    }

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=cur_sum;j++)
        {
            if(a[i]>j) // i th item is heavier than j , so we can't take it
                dp[i][j]= dp[i-1][j];
            else
                dp[i][j]= max( dp[i-1][j], dp[i-1][j-a[i]]+a[i] );

        }
    }
    return dp[N][cur_sum];
}
main()
{
        int test_cases,K,i;
       S(test_cases);
        int a[1002];
        int sum;
        while(test_cases--)
        {
            a[0]=0;

            N=fastRead_int();
            K=fastRead_int();
            sum=0;
            for(i=1;i<=N;i++)
            {
                a[i]=fastRead_int();
                sum+=a[i];
            }
           // cout<<sum<<endl;
           int x=solve(a,sum,K,0);
            if(x==K)
                printf("1\n");
            else
               printf("0\n");
        }


return 0;
}
