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
LL lcm[100005];
int i,j,k;
int primes_factor[102][27];
LL mod=1000000007;
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};//26 size
/*LL gcd(LL a,LL b)
{
	LL c;
	while(b>0) c=a%b, a=b, b=c;
	return a;
}
void precompute()
{
    lcm[2]=2;
    for(int i=3;i<=100;i++)
    {
        lcm[i]=(lcm[i-1]*i/gcd(lcm[i-1],i) )%mod;
    }
}*/
LL ans;
LL fast_mod_pow(int a,int b)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2)
            prod= (prod*a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return prod%mod;
}
void precompute()
{
    memset(primes_factor,0,sizeof(primes_factor));
    for(i=2;i<=100;i++)
    {
        int num=i;
        for(j=0;primes[j]<=num && j<26;j++)
        {
            while(num%primes[j]==0)
            {
                num/=primes[j];
                primes_factor[i][j]++;
            }
        }
    }
    /*
    for(i=2;i<=100;i++)
    {
        for(j=0;j<26;j++)
            if(primes_factor[i][j]!=0)
                printf("%d %d\n",primes[j], primes_factor[i][j]);
        printf("\n");
    }*/
    lcm[1]=2;
    for(j=2;j<=100;j++)
    {
        int maxm[27];
        ans=1;
        memset(maxm,0,sizeof(maxm));
        for(i=2;i<=j;i++){
            for(k=0;k<26;k++)
            {
                maxm[k]= max(maxm[k],primes_factor[i][k]);
            }
        }
        for(k=0;k<26;k++)
        {
            ans= (ans* fast_mod_pow(primes[k],maxm[k]))%mod;
        }
        lcm[j]= ans%mod;
    }
}

main()
{
    precompute();
    int test_cases,n;
    S(test_cases);
    while(test_cases--)
    {
        S(n);
        printf("%lld\n",(lcm[n]+1)%mod);
    }
return 0;
}
