#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#include<bitset>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;

LL fast_pow(LL a,LL b)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2)
            prod= prod*a;
        b/=2;
        a=a*a;
    }
    return prod;
}
main()
{
    LL N,i;
    cin>>N;
    LL num;
    LL  ans=0;
    LL bit[32];
    memset(bit,0,sizeof(bit));
    while(N--)
    {
        scanf("%lld",&num);
        for(i=0;i<31;i++) // log(10^9) base2= 29
        {
            if( num&(1<<i))
                bit[i]++; // number of bits at index i is increase by 1
        }
    }
    ans= bit[0]*(bit[0]-1)*0.5;
    for(i=1;i<31;i++)
    {
        ans+= bit[i]*(bit[i]-1)*fast_pow(2,i-1);
    }
    cout<<ans<<endl;



return 0;
}
