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
using namespace std;

inline void fastLongInput(long long &x) {

    register int c = getchar();

    x = 0;

    int neg = 0;



    for(; ((c<48 || c>57) && c != '-'); c = getchar());



    if(c=='-') {l

        neg = 1;

        c = getchar();

    }



    for(; c>47 && c<58 ; c = getchar()) {

        x = (x<<1) + (x<<3) + c - 48;

    }



    if(neg)

        x = -x;

}

LL gcd(LL a,LL b)
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
main()
{
     int test_cases;
    S(test_cases);
    long long N,ans,i,x;
    LL gc,den;

    //int x;
    while(test_cases--)
    {
        ans=0;
       // scanf("%lld",&N);
       fastLongInput(N);
        x=sqrt(N);
        for(i=1;i<=x;i++)
        {
            ans+= (N/i);
           // cout<<i<<"   :   "<<N/i<<endl;
        }

      //  cout<<ans<<endl;
       ans= (ans<<1) - x*x;
       ans= (LL) ans;
            den= (LL)(N*N);
         // printf("ans= %lld , den=%lld\n",ans,den);
            gc= gcd(ans,den);
            printf("%lld/%lld\n",ans/gc,den/gc);
    }


return 0;
}
