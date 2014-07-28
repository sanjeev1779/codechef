#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
#define VI vector<int>
using namespace std;
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline void writeInt(int x)
{
     if(x==-1)
     {
              PUTCHAR('-');
              PUTCHAR('1');
              PUTCHAR('\n');
     }
     else
     {
       int i = 10;
       char buf[11];
      // buf[10] = 0;
      buf[10] = '\n';

     do
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
     }
}

inline int fastRead_int()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};

unsigned int fast_mod_power(LL a,unsigned int b,LL mod)
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

  return  (unsigned int )(mul%mod);
}
unsigned int mod,prod[100001][25];
int N,T,x,l,r;
vector<VI> vec(100);
void precompute_prime_factor()
{
 for(int i=1; i<100;i++)
 {
  int j=0;
  int x=i+1;
  while(x!=1)
  {
     while(x% primes[j]==0)
      {
          vec[i].pb(j);
          x=x/primes[j] ;
      }
     j++;
  }
 }
}

int main()
{
    precompute_prime_factor();
    int i,j;
    LL ans;
    //cin>>N;
    N= fastRead_int();
    for(i=0;i<25;i++)
        prod[0][i]=0;
    //cin>>x;
    x= fastRead_int();
      for(j=0;j<vec[x-1].size();j++)
        prod[0][vec[x-1][j]]++;
    for(i=1;i<N;i++)
    {
      for( j=0;j<25;j++)
       prod[i][j]=prod[i-1][j];
      //cin>>x;
      x=fastRead_int();

      for(j=0;j<vec[x-1].size();j++)
        prod[i][vec[x-1][j]]++;
    }
    //cin>>T;
    T= fastRead_int();
    LL modu;
    while(T--)
    {
        ans=1;
        //cin>>l;
        //cin>>r;
        l =fastRead_int();
        r=fastRead_int();
        //cin>>modu;
        modu= fastRead_int();

      l--;r--;
      if(l>0)
        {
            l--;
            for(i=0;i<25;i++)
                ans= (ans * fast_mod_power(primes[i],prod[r][i]-prod[l][i],modu))%modu;
        }
        else
        {
            for(i=0;i<25;i++)
                ans= (ans * fast_mod_power(primes[i],(prod[r][i]),modu))%modu;
        }
        //cout<<(ans%modu)<<endl;
        writeInt(ans%modu);
    }
	return 0;
}
