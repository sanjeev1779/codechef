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
LL mod= 1000000007;
LL fast_mod_pow(LL a, LL b)
{
    LL prod=1;
    while(b>0)
    {
        if(b&1)
            prod= (prod*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return prod;
}
main()
{
    int test_cases;
    S(test_cases);
    LL N,M,Qr,K,seq;
    while(test_cases--)
    {
        scanf("%lld %lld %lld %lld",&N,&M,&Qr,&K);
        if(M<=Qr)
            seq=0;
        else
        {
            seq=( fast_mod_pow( Qr+1, N )%mod + fast_mod_pow(Qr-1,N)%mod +2* fast_mod_pow(Qr,N)%mod + mod ) %mod;
            seq=( seq* (M-Qr)%mod) %mod;
        }
        printf("%lld\n",seq);

    }
return 0;
}
