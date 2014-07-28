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

long long gcd(long long a,long long b)
{
	long long c;
	while(b>0) c=a%b, a=b, b=c;
	return a;
}
main()
{
int test_cases;
long long i,c,g,k,n;
cin>>test_cases;
while(test_cases--)
{
   cin>>n>>k;
   c=1;
   if(k>n-k)
      k=n-k;
   for(i=1;i<=k;i++)
   {
        g=gcd(c,i);
        c=c/g;
        c*= (n-i+1)/(i/g);
   }
   cout<<c<<endl;
}
return 0;
}
