#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define ULL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;


ULL gcd(ULL a,ULL b)
{
	ULL c;
	while(b>0) c=a%b, a=b, b=c;
	return a;
}

ULL solve(ULL n, ULL k)
{
    ULL c=1,g,i;
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
    ULL n,k,ans;
    S(test_cases);
    while(test_cases--)
    {
        scanf("%lld %lld",&n,&k);
        ans= solve(n-1,k-1);
        printf("%lld\n",ans);
    }

return 0;
}
