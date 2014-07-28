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

LL fast_pow(LL a,LL b, LL m)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2)
            prod=(prod*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return prod;
}
main()
{
    int test_cases;
    scanf("%d",&test_cases);
    LL n,k,p,ans,i;
    while(test_cases--)
    {
        scanf("%lld %lld %lld",&n,&k,&p);
        ans=0;
        for(i=1;i<=n;i++)
        {
            ans= (ans+ fast_pow(i,k,p))%p;
        }
        printf("%lld\n",ans);
    }

return 0;
}
