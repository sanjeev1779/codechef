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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
vector<int>primes;
vector<LL>ans;
int sieve[1000002];
int small_prime[]={3,5,7,11,13,17,19,23,29,31,37,41};
void sieve_small()
{
    int limit,i,ans=0,n,m;
    limit= 1000002;
    int sqrtlimit = sqrt(limit);
    vector<bool> sieve(limit+1, false);
    for (n=4;n<=limit;n=n+2)
    {
        sieve[n]=true;
    }
    for(n=3;n<sqrtlimit;n+=2)
    {
        if(!sieve[n])
        {
            for(m=n*n;m<=limit;m+=(2*n))
            {
                sieve[m]=true;
            }
        }
    }
    for(i=2;i<=limit;i++){if(!sieve[i])primes.pb(i);}
}
LL fast_mod_pow(int a, int b)
{
    LL prod=1;
    LL x= (LL) a;
    while(b>0)
    {
        if(b&1)
            prod=(prod*x);
        x= (x*x);
        b=b>>1;
    }
    return prod;
}
// precompute from 1 to 10^6 which are not prime
void precompute()
{
   int l = primes.size(),i,j; LL val;
   int length_of_num;
    for(i=0;i<l;i++)
    {
        for(j=0;j<12;j++)
        {
            length_of_num=  (small_prime[j]-1)*log(primes[i])/log(10);
            if(length_of_num>12)
                break;
            val= fast_mod_pow(primes[i],small_prime[j]-1);
            ans.pb(val);
           // cout<<val<<endl;
        }
    }
}
int sieve_range(LL m, LL n)
{
    int cnt=0;
    // generate prime from m and n
    if(m<=2)
            {
                cnt++;
                m++;
            }
    LL i,a,j;
    LL limit= n;
    LL sqrtlimit = sqrt(n);
    //vector<bool> sieve(limit+1, false);
   // int sieve[1000002];
    for(i=0;i<=n-m+2;i++)
        sieve[i]=0;
    if(m%2==0)//even
        i=m;
    else i=m+1; // odd

    for(;i<=n;i=i+2) //make evens unprime
        sieve[i-m]=1; // not prime

    for(i=3;i<=sqrtlimit;i=i+2)
    {
        if(i>=m && sieve[i-m]==1)
            continue;

        if(i*i>=m)
            j=i*i;
        else
        {
            a=(m-i*i)%(2*i);
            if(a==0)j=m;
            else
                j=m+(2*i-a);
        }

            for(;j<=n;j=j+(2*i))
            {
                sieve[j-m]=1;
            }

    }
    for(i=0;i<=n-m;i++)
    {
        if(!sieve[i]) //if sieve[i]=0
           {
             //  primes.pb(i+m);
              // printf("%lld\n",i+m);
              cnt++;
           }
    }
return cnt;
}


//end of sieve
main()
{
    sieve_small();
    int kisses_by_irina;
    precompute();
    sort(ans.begin(),ans.end());
    int t;
    LL L,R;
    S(t);
    LL m,n;
    while(t--)
    {
        SL(L);SL(R);
        if(L==R && L==1)
        {
            printf("0\n");
            continue;
        }
        kisses_by_irina= upper_bound(ans.begin(),ans.end(),R)- lower_bound(ans.begin(),ans.end(),L);
        kisses_by_irina+=sieve_range(L,R);
        printf("%d\n",kisses_by_irina);
    }
return 0;
}
