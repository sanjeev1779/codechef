#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
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
LL gcd(LL a, LL b)
{
    LL temp;
    while(b>0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
LL fast_modular_pow(LL a, int b, LL mod)
{
    LL prod= 1;
    while(b>0)
    {
        if(b%2)
            prod= (prod*a)%mod;
        a= (a*a)%mod;
        b=b/2;
    }
    return (prod%mod);
}

main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int k;
        LL i,x;
        LL n,mod;
        LL sum=0;
        cin>>n>>k>>mod;
        for(i=1;i<=n;i++)
        {
            if(gcd(i,n)==1)
            {
                x= fast_modular_pow(i,k,mod);
                sum= (sum+x)%mod;
            }
        }
        cout<<sum%mod<<endl;
return 0;
}
