#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define SI(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
vector<int>primes;
int n,i;
int num_of_primes;
int check_small_prime(int n)
{
    int small_prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    for(i=0;i<13;i++)
    {
        if(n==small_prime[i])
            return 1;
    }
    return 0;
}
void sieve_algo()//generate all prime less than sqrt(maxm_value)
{
    int limit=1000005,i,ans=0,n,m;
    int sqrtlimit = sqrt(limit);
    vector<bool> sieve(limit+1, false);
    for (n=4;n<=limit;n=n+2)
    {
        sieve[n]=true;
    }
    for(n=3;n<sqrtlimit;n=n+2)
    {
        if(!sieve[n])
        {
            for(m=n*n;m<=limit;m=m+(2*n))
            {
                sieve[m]=true;
            }
        }
    }
    for(i=2;i<=limit;i++)
    {
        if(!sieve[i]) //if sieve[i]=0
           {
               primes.pb(i);
           }
    }
}
// sieve end

// check for special number
int cnt,num_of_factors,factor;
int check_special(LL num)
{
    cnt=0;
    factor=0;
    LL temp=num;
    num_of_factors=0;
    for(i=0;primes[i]*primes[i]<=num && i<num_of_primes;i++)
    {
        if(num%primes[i]==0)
            num_of_factors++;
        if(num_of_factors>1)
            break;
        while(num%primes[i]==0)
        {
            factor= primes[i];
            num/= primes[i];
            cnt++;
        }
    }
    if(num!=1)
    {
        if(factor==0)
            return 1;
        if(factor==num)
            cnt++;
        else{
            num_of_factors++;
        }
    }
   // cout<<"i and cnt=  and num of factors  :: "<<temp<<" : "<<cnt<<" : "<<num_of_factors<<endl;
    if(num_of_factors>1)
        return 0;
    if(check_small_prime(cnt+1))
        return 1;
    return 0;
}
main()
{
    sieve_algo();
    num_of_primes= primes.size();
  //  cout<<"num _fo primes= "<<primes.size()<<endl;
    LL i,L,R;
    int test_cases,special;
    SI(test_cases);
    while(test_cases--)
    {
        special=0;
        SL(L);SL(R);
        for(i=L;i<=R;i++)
        {
            if(check_special(i))
                special++;
        }
        printf("%d\n",special);
    }
return 0;
}

