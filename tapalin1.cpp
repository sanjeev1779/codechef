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
LL mod=1000000007;


LL fast_mod_power(LL a, LL b, LL mod)
{
  LL mul=1;
    while(b>0)
    {
      switch(b%4)
      {
        case 3: mul= (mul*a)%mod;
        case 2: mul= (mul*a)%mod;
        case 1: mul= (mul*a)%mod;
      }
      b/=4;
      a=((((((a*a)%mod)*a)%mod)*a)%mod);
    }

  return  (LL )(mul%mod);
}

main()
{

    LL i,j,N,ans=0,x;
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        ans=0;
        scanf("%lld",&N);
        // ans= 26^1+ 26^1+ 26^2+ .... till N
        x= (N+1)/2;
        j= fast_mod_power(26,x,mod);
        LL inv25= 280000002;
        ans= (52* (j-1)%mod * 280000002 )%mod;
        if(N%2==1)
        {
            //odd den sub 26^N, since one time it is extra added
            ans= (ans+ mod-j)%mod;
        }
        cout<<ans%mod<<endl;

    }

return 0;
}
