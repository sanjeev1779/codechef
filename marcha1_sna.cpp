#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
LL gcd(LL a, LL b)
{
    LL temp;
    while(b>0)
    {
        temp= a%b;
        a=b;
        b=temp;
    }
    return a;
}
main()
{
      int t;
        S(t);
        LL n,i;
        while(t--)
        {
            SL(n);
            i= n/2;
            while(gcd(i,n)!=1)
            {
                i--;
            }
            printf("%lld\n",i);
        }
return 0;
}
