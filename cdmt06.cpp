#include<bits/stdc++.h>
using namespace std;
long long int mod= 1000000007;
#define LL long long int
void multiply(LL F[2][2], LL M[2][2])
{
  LL x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
  LL y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
  LL z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
  LL w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
/* Optimized version of power() in method 4 */
void power(long long int F[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
  LL M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
/* function that returns nth Fibonacci number */
long long int fib(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n);
  return F[0][0];
}

main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
            scanf("%lld",&n);
            printf("%lld\n",fib(n)%mod);
    }
    return 0;
}
