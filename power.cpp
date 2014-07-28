#include<iostream>
#define LL long long
using namespace std;

LL fast_pow(int a,LL d,LL mod)
{
  LL mul=1;
    while(d>0)
    {
      switch(d%4)
      {
        case 3: mul= (mul*a)%mod;
        case 2: mul= (mul*a)%mod;
        case 1: mul= (mul*a)%mod;
      }
      d/=4;
      a=((((((a*a)%mod)*a)%mod)*a)%mod);
    }

  return  (mul%mod);
}


int main()
{
    int T;
    int a;
    LL b,m;
    LL ans;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>m;
        cout<<fast_pow(a,b,m)<<endl;
    }
}
