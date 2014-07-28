#include<iostream>
#include<stdio.h>
#include<cmath>
#define LL long long
using namespace std;
LL mod = 1000000007;
LL fast_mod_pow(LL n)
{
    LL prod=1;
    LL a=2;
    while(n>0)
    {
        if(n&1)
            prod=(prod*a)%mod;
        a= (a*a)%mod;
        n=n>>1;
    }
    return prod%mod;
}
main()
{

    int test_Cases;
    LL n,ans,x;
    scanf("%d",&test_Cases);
    while(test_Cases--)
    {
        scanf("%lld",&n);
        x=fast_mod_pow(n);
    //    cout<<x<<endl;
        ans= (x%mod-1)%mod;
        printf("%lld\n",ans);
    }
return 0;
}
