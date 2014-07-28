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
string str;
int ispalinMem[5001][5001];
int n;
int i,l,r;

void precompute()
{
    for (i = 0; i < n; i++){
            l = r = i;
            while (l >= 0 && r < n && str[l] == str[r]){
                ispalinMem[l][r] = true;
                l--;
                r++;
            }
            l = i - 1;
            r = i;
            while (l >= 0 && r < n && str[l] == str[r]){
                ispalinMem[l][r] = true;
                l--;
                r++;
            }
        }
}
int solve(string str)
{
    int l= str.size(),i,j;
    int dp[l+1];
    for(i=0;i<l;i++)
        dp[i]=i;

    for(i=0;i<l;i++)
    {

        if(ispalinMem[0][i]==true)
              {
                  dp[i]=0;
                 // cout<<"first\n";
              }
        else
        for(j=0;j<i;j++)
        {
                if( ispalinMem[j+1][i]==true  && dp[i] >dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                    }
        }
       // cout<<"i "<<i<<" dp ="<<dp[i]<<endl;
    }
    return dp[l-1]+1;
}
main()
{
    int test_cases;
    S(test_cases);
    while(test_cases--)
    {
        S(n);
        memset(ispalinMem,-1,sizeof(ispalinMem));
        cin>>str;
        precompute();
        //cout<<"palin "<<ispalinMem[2][3]<<endl;
        cout<<solve(str)<<endl;
       /* cout<<endl;
        for(i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                cout<<ispalinMem[i][j]<<" ";
            }
            cout<<endl;
        }*/
    }

return 0;
}
