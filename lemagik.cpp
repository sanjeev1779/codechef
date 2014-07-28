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
#define mp make_pair
using namespace std;

int edit_dis(char a[], char b[],int n1, int n2)
{
    int dp[n1+1][n2+1];
    int i,j;
    memset(dp,-1,sizeof(dp));
    for(i=0;i<=n1;i++)
        dp[i][0]=i;
    for(i=0;i<=n2;i++)
        dp[0][i]=i;

    //main dp
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=min( dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]));
            else
            {
                dp[i][j]= min( dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
            }
        }
    }
    return dp[n1][n2];


}
main()
{
    int test;
    S(test);
    char a[505],b[505];
    int n1,n2,i;
    while(test--)
    {
        cin>>a>>b;
        n1=strlen(a);
        n2=strlen(b);
        cout<<edit_dis(a,b,n1,n2)<<endl;
    }
return 0;
}
