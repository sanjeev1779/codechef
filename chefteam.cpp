#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
typedef unsigned long long ULL;

/*
inline int fastread()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
}; */

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
ULL c,k,n;
cin>>test_cases;
while(test_cases--)
{
   cin>>n>>k;
   c= solve(n,k);
   cout<<c<<endl;
}
return 0;
}
