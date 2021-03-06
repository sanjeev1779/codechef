#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string.h>
#define LL long long
using namespace std;
main()
{
    //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
    int test_cases,i,j,n,m,ans,k;
    int mouse[105][105];
    int dp[102][102][2];
    char row[105];
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        scanf("%d%d",&n,&m);
        memset(mouse,0,sizeof(mouse));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            scanf("%s",row);
            for(j=1;j<=m;j++)
            {
                mouse[i][j]=row[j-1]- '0';
            }
        }


        // now check the path of the LE

        for(i=0;i<102;i++)
        {
                    dp[i][0][0]=dp[i][0][1]=dp[0][i][1]=dp[0][i][0]=100000;
        }
        dp[1][1][0]=dp[1][1][1]=mouse[1][1]+mouse[1][2]+mouse[2][1];

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i!=1 || j!=1)
                {
                    dp[i][j][0]=min(dp[i-1][j][0]+mouse[i][j-1]+mouse[i][j+1]+mouse[i+1][j],dp[i-1][j][1]+mouse[i][j+1]+mouse[i+1][j]);
                    dp[i][j][1]=min(dp[i][j-1][1]+mouse[i+1][j]+mouse[i-1][j]+mouse[i][j+1],dp[i][j-1][0]+mouse[i+1][j]+mouse[i][j+1]);

                }
            }
        }
        printf("%d\n",min(dp[n][m][1],dp[n][m][0]));

    }
return 0;
}
