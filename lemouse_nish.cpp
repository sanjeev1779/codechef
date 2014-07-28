#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
#define inf 1000000
using namespace std;
main()
{
    int test_cases,i,j,n,m,ans,k;
    int mouse[102][102];
    int dp[102][102][2];
    char row[102];
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>row;
            for(j=0;j<m;j++)
            {
                mouse[i][j]=row[j]- '0';
            }
        }

       dp[0][0][0]= dp[0][0][1]= mouse[0][0];
       for(i=0;i<n;i++)
       {
           for(j=0;j<m;j++)
           {

               if(i==0 && j==0)
                 {
                     dp[i][j][0]+= mouse[i+1][j]+ mouse[i][j+1];
                     dp[i][j][1]+= mouse[i+1][j]+ mouse[i][j+1];
                 }
               else if(i==0 && j<m-1)
                 {
                     dp[i][j][0]+= dp[i][j-1][0] + mouse[i+1][j]+ mouse[i][j+1];
                     dp[i][j][1]= inf;
                 }
                 else if(i==0 && j==m-1)
                 {
                     dp[i][j][0] + = dp[i][j-1][0]+ mouse[i+1][m];
                     dp[i][j][1]= inf;
                 }
                 else if(j==0 && i<n-1)
                 {
                     dp[i][j][1]+= dp[i-1][j][1]+ mouse[i+1]+ mouse[j+1];
                     dp[i][j][0]= inf;
                 }

                 else if(j==m-1 && i<n-1)
                 {
                     dp[i][j][0]+= dp[i-1][j][0]+ mouse[i+1][j];
                     dp[i][j][1]+= dp[i-1]mouse[i+][j];
                 }

           }
       }
    }
return 0;
}
