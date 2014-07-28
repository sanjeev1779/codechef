#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <math.h>
#define LL long long

using namespace std;

bool check[1000000]; //used for sieving upto 10^6

vector <long long int> primes; //to store primes upto 10^6

int preCompute() //for finding prime nos upto 10^6
{
    for(long int i=0;i<=1000000;i+=2)
    {
        check[i]=false;
    }

    check[1]=false;check[2]=true;

    for(long int i=3;i<1000000;i+=2)
    {
        check[i]=true;
    }

    for(long int i=3;i<=1000;i+=2)
    {
        if(check[i])
        {
            long int j=i*i;

            while(j<=1000000)
            {
                check[j]=false;

                j+=i;
            }
        }
    }

    for(long int i=2;i<1000000;i++)
    {
        if(check[i])
        {
            primes.push_back(i);
        }
    }

    return 0;
}

int countDigits(long long int base, long long int exp) //for counting digits
{
    return (exp*log10(base))+1;
}

long long int fastPow(long long int a,long long int n) //finding power
{
    long long int result = 1;
    long long int power = n;
    long long int value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;}
        value = value*value;
        power /= 2;
        //power >>= 1;
    }
    return result;
}

vector <long long int> ans;

long int sieve[1000002];

long int sieve_range(LL m, LL n)
{
    long int cnt=0;
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

int main()
{
    preCompute();

    for(long int i=0;i<primes.size();i++)
    {
        long long int temp;

        for(long int j=1;;j++)
        {
            int num=countDigits(primes[i],primes[j]-1);

            if(num<13)
            {
                temp = fastPow(primes[i],primes[j]-1);

                ans.push_back(temp);
            }

            else
            {
                break;
            }
        }
    }

    int t;

    scanf("%d",&t);

    while(t--)
    {
        long long int l,r,k=0;

        scanf("%lld %lld",&l,&r);

        for(long long int i=0;i<ans.size();i++) //all special nos are stored in vector called ans
        {
            if(ans[i]<=r&&ans[i]>=l)
            {
                //cout << i << " " << ans[i] << endl;

                k++;
            }
        }

        //cout << k << endl;

        k+=sieve_range(l,r);

        printf("%lld\n",k);
    }

    return 0;
}
