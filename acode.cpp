#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
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
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    string str;

    int i,l;
    int dp[5005];
   // l= str.size();
    while(1)
    {
        cin>>str;
        l= str.size();
        if(l==1 && str[0]=='0') break;
        cout<<l<<endl;
        dp[0]=0;
        dp[1]=1;
        if(l>=1){
        if(str[0]<='2' && str[1]<='6')
            dp[2]=2;
        else dp[2]=1;
        }
        for(i=3;i<=l;i++)
        {
            if(str[i-2]<='2' && str[i-1]<='6')
            {
                dp[i]=dp[i-1]+1;
            }
            else dp[i]=dp[i-1];
            cout<<dp[i]<<endl;
        }
        cout<<dp[l]<<endl;
    }
return 0;
}
