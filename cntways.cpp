#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define LI long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;
LL mod= 1000000007;
LL maxm=800002;
LL fact[800002];
LL InvFact[800002];
int i;
LL fast_mod_power(LL a,LL b)
    {
        LL prod=1;
            while(b>0)
            {
                if(b%2==1)
                   prod= (a*prod)%mod;
                a= (a*a)%mod;
                b/=2;
            }
            return prod%mod;
    }


void precompute()
{

        fact[0]=0;
        fact[1]=1;
        for(i=2;i<=maxm+1;i++)
        {
            fact[i]=(i*fact[i-1])%mod;
        }

        // find the invers of fact(maxm)
        InvFact[maxm-2]= fast_mod_power(fact[maxm-2],mod-2)%mod;

        for(i=maxm-2;i>=1;i--)
        {
            InvFact[i-1]= (i*InvFact[i]) %mod;
        }
}

LL ways(LL N,LL M)
{
    LL paths= (fact[N+M]*((InvFact[N]*InvFact[M])%mod))%mod;
    return paths;
}



main()
{
    precompute();
    int R,k;
    LL N,M,A,B;
    S(R);
    LL ans=0;

    while(R--)
    {
        cin>>N>>M>>A>>B;
        ans=0;
        if(A==0 || B==0)
        {
            ans=ways(N,M);
        }
        else
            {
        for(k=A;k<=N;k++)
        {
            cout<<ways(k,M-B)<<"*"<<ways(N-k,B-1)<<endl;
            ans=( ans+(ways(k,M-B)*ways(N-k,B-1))%mod)%mod;
        }
        }
        cout<<ans<<endl;
    }

return 0;
}
