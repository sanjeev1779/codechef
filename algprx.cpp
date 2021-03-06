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

int limit=  1000002;
int sqrtlimit = sqrt(limit);
vector<bool> sieve(limit+1, false);
vector<int> prime;
int n,i;
void  sieve_algo()
{

    for (n=4;n<=limit;n=n+2)
        sieve[n]=true;

    for(n=3;n<sqrtlimit;n=n+2)
    {
        if(!sieve[n])
        {
            for(int m=n*n;m<=limit;m=m+(2*n))
            {
                sieve[m]=true;
            }
        }
    }
    for(i=2;i<=limit;i++)
    {
        if(!sieve[i]) //if sieve[i]=0
          {
              prime.pb(i);
             // cout<<"o= "<<i<<endl;
          }

    }
}
main()
{
    sieve_algo();
    int x,i,test_cases;
    S(test_cases);
    LL sum;
    while(test_cases--)
    {
        sum=0;
        S(x);
        for(i=0;prime[i]<x;i++)
            sum+= prime[i];
        printf("%lld\n",sum);
    }

return 0;
}
