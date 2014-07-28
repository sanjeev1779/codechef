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
int maxm= 800002;
LL mod= 1000000007;
LL fact[800002];
LL invfact[800002];

LL fast_mod_power(LL a, LL b)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2==1)
            prod=(a*prod)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return prod%mod;
}
void precompute()
{
    //calculte factorial
    int i;
    fact[0]=1;
    fact[1]=1;
    for(i=2;i<=maxm;i++)
    {
        fact[i]= (fact[i-1]*i)%mod;
    }

    //calculte inverse of factorial
    invfact[maxm]= fast_mod_power( fact[maxm],(mod-2))%mod;

    for(i=maxm;i>=1;i--)
    {
        invfact[i-1]= (i*invfact[i])%mod;
    }
}
LL ways(int n, int m)
{
    LL paths= (fact[n]* (invfact[m]*invfact[n-m])%mod )%mod;
    return paths;
}
main()
{
    precompute();
    int R,A,B,M,N,k;
    S(R);
    LL ans=0;
    while(R--)
    {
        ans=0;
        S(N);
        S(M);
        S(A);
        S(B);

            for(k=A;k<=(N);k++)
            {
                //ans= ( ans+( ways(k,B-1)*1*ways(N-k,M-B) )%mod )%mod;
                ans= ( ans+  (  ways(k+M-B,M-B)*ways(N-k+B-1,B-1) )%mod )%mod;
            }
        cout<<ans%mod<<endl;
    }

return 0;
}
