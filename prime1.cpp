#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
using namespace std;

LL limit=  sqrt(1000000000)+2; //generate all prime less than sqrt(1000000000)
LL sqrtlimit = sqrt(limit);
vector<bool> sieve(limit+1, false);
vector<int> prime;
int n,i;
void  sieve_algo()
{

    for (n=4;n<=limit;n=n+2)
    {
        sieve[n]=true; //making odd number false, as they cant be prime
    }
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

int check_prime(int num)
{
    int rem=1;
    int num_of_primes= prime.size();
    for(i=0;prime[i]*prime[i]<=num && i<num_of_primes;i++)
    {
        if(num==prime[i])
        {
            rem=1;
            break;
        }
        else if(num%prime[i]==0)
        {
            rem=0; // not a prime number
            break;
        }
    }
    if(rem==0)
        return 0; // not a prime number
    else
        return 1; // a prme number

}

main()
{
    sieve_algo();
    int test_Cases;
    LL m,n;
    cin>>test_Cases;
    while(test_Cases--)
    {
        //scanf("%lld %lld",&m,&n);
        cin>>m>>n;
        if(m==1)
            m++;// since 1 is not a prime number
        for(int j=m;j<=n;j++)
        {
                if(check_prime(j))
                    {
                        printf("%d\n",j);
                    }
        }
        printf("\n");
    }


return 0;
}
