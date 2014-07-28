#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define ULL unsigned long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
ULL ans[600002];
ULL mod=1000000007;
inline void fastLongInput(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-') {
            neg = 1;
        c = getchar();
    }
    for(; c>47 && c<58 ; c = getchar()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}
ULL bin(int n)
{
    ULL bn=0,pow=1;
    int rem;
    while(n>0)
    {
        rem=n%2;
        bn+=rem*pow;
        pow=pow*10;
        n/=2;
    }
    return bn;
}

ULL fast_mod_pow(ULL a,int n)
{
    ULL prod=1;
    a=2;
    ULL b= bin(n)*2;
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
    for(int i=1;i<=100;i++)
    {
        ans[i]= fast_mod_pow(2,i);
        printf("%lld ,",ans[i]);
    }
}
main()
{
    precompute();
    int test_cases,n;
return 0;
}
