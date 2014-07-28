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
#define mp make_pair
using namespace std;
vector<int>primes;
LL maxm=1000000000000;
vector<LL>ans;
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
void sieve()
{
    int limit,i,ans=0,n,m;
    limit= 1000000;
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
void precompute()
{
    int l = primes.size(),i,j; LL val;
    for(i=0;i<l;i++)
    {
        for(j=0;j<l;j++)
        {
            val= fast_mod_pow(primes[i],primes[j]-1);

            if(val>maxm)
                break;
            ans.pb(val);
            cout<<val<<endl;
        }
    }
}
main()
{
    sieve();
    precompute();
    int l_ans= ans.size();
    cout<<l_ans<<endl;
    sort(ans.begin(),ans.end());
    //for(int i=0;i<100;i++)
      //  printf("%d\n ",ans[i]);
    LL L,R;
    int test_Cases,kiss;
    S(test_Cases);
    while(test_Cases--)
    {
        scanf("%lld %lld",&L,&R);
        kiss= upper_bound(ans.begin(),ans.end(),R)- lower_bound(ans.begin(),ans.end(),L);
        printf("%d\n",kiss);
    }
return 0;
}
