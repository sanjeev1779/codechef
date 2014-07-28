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
int N;
int a[61];
LL dp[61][10001];
int gcd(int a, int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
LL amsgame2(int pos, int cur_gcd)
{
    LL gc;
    if(pos==N && cur_gcd==1)
        return 1;
    if(pos==N && cur_gcd!=1)
        return 0;
    if(dp[pos][cur_gcd]>-1)
        return dp[pos][cur_gcd];


        gc= amsgame2(pos+1,cur_gcd) + amsgame2(pos+1,gcd(cur_gcd,a[pos]));
        dp[pos][cur_gcd]=gc;
            return gc;

}
main()
{

    int test_cases,i;
    LL ans;
    S(test_cases);


    while(test_cases--)
    {
        S(N);
        ans=0;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<N;i++)
            S(a[i]);


        for(i=0;i<N-1;i++)
            ans=ans+ amsgame2(i+1,a[i]);
    printf("%lld\n",ans);
    }

return 0;
}
