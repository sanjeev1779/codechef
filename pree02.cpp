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

int check(LL num)
{
    int flag=0;
    int rem;
    while(num>0)
    {
        rem= num%10;
        if(rem==3 || rem==5 || rem==6)
        {
            flag=1;
        }
        num/=10;
    }
    if(flag==1)
        return 1;
    else
        return 0;
}
int solve(LL num)
{
    int cnt=0;
    LL i;
    for(i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            if( check(i) )
                cnt++;
            if(i*i!=num)
            {
                if( check(num/i) )
                cnt++;
            }
        }
    }
    return cnt;
}
main()
{
    int t;
    S(t);
    LL n;
    int ans;
    while(t--)
    {
        scanf("%lld",&n);
        ans= solve(n);
        printf("%d\n",ans);
    }

return 0;
}
