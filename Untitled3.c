#include<stdio.h>
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
main()
{

int test_cases;
ULL i,c,g,k,n;
scanf("%d",&test_cases);
while(test_cases--)
{
   scanf("%llu %llu",&n,&k);
   c=1;
   if(k>n/2)
      k=n-k;
   for(i=1;i<=k;i++)
   {
        g=gcd(c,i);
        c=c/g;
        c*= (n-i+1)/(i/g);
   }
   printf("%llu\n",c);
}
return 0;
}
