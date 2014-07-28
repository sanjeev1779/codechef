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
int maxm=1000002;

LL gcd(LL m, LL n) {
   if ((m % n) == 0)
      return n;
   else
      return gcd(n, m % n);
}
LL num=0,den=0;
void precompute(LL N, LL M)
{
    LL i;
    den=1;
    num=1;
    for(i=2;i<=N;i++)
    {
       num=(num+den)%M;
       den= (den+num)%M;
    }
}
main()
{
   // precompute();
    int test_cases;
    S(test_cases);
    LL gc;
    LL N,M;
    while(test_cases--)
    {
        scanf("%d %lld",&N,&M);
       // memset(a,0,sizeof(a));
        precompute(N,M);
        gc= 1;
     //   cout<<a[N][0]<<" : "<<a[N][1]<<endl;
       // cout<<gc<<endl;
        printf("%d/%d\n", (num/gc),(den/gc));
    }

return 0;
}
