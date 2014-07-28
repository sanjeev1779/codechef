#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define ULL unsigned long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;


LL gcd(LL a,LL b)
{
	LL c;
	while(b>0) c=a%b, a=b, b=c;
	return a;
}

LL solve(LL n, LL k)
{
    LL c=1,g,i;
    if(k>n)
        return 0;
    if(k>n-k)
      k=n-k;
   for(i=1;i<=k;i++)
   {
        g=gcd(c,i);
        c=c/g;
        c*= (n-i+1)/(i/g);
   }
   return c;
}

main()
{
    int test_cases;
    S(test_cases);
    int N,K,i;
    LL ans,x,mod=1000000007;
    for(int j=1;j<=test_cases;j++)
    {
        ans=0;
        S(N);S(K);
        LL a[N+2];
        a[0]=0;
        for(i=1;i<=N;i++)
        {
            SL(a[i]);
        }
        sort(a,a+N+1);
        for(i=N;i>=K;i--)
        {
            x=((solve(i-1,K-1)%mod)*a[i])%mod;
            ans= (ans+x)%mod;
        }
        printf("Case #%d: %lld\n",j,ans);
    }
return 0;
}
