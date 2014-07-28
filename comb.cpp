#include<stdio.h>
#include<iostream>
using namespace std;
#define ULL  long long
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
    ULL n,r;
    ULL i;
    ULL T;
    ULL ans[70];
    for(i=4;i<=67;i++)
    {
        ans[i]= solve(i,i/2);
    }
    cin>>T;
    while(T--)
    {
        scanf("%lld",&n);
        if(n==2 || n==3)
            printf("%lld\n",n);
        else
        {
            i=4;
            while(ans[i]<n)
            {
                i++;
            }
            printf("%lld\n",i);
        }

    }


return 0;
}
