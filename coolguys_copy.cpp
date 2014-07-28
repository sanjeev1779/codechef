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
LL gcd(LL a,LL b)
{
   if(a%b==0)
     return b;
   else return gcd(b,a%b);
}
main()
{
    int test_cases;
    S(test_cases);
    LL N,ans,gc,den,i;
    LL start_index;
    LL x,j;
    for(j=2;j<100;j++)
    {
        ans=0;
        //scanf("%lld",&N);
        N=j;
        x=sqrt(N);
        for(i=1;i<=x;i++)
        {
            ans+= (N/i);
           // cout<<i<<"   :   "<<N/i<<endl;
        }

        ans=2*ans- x*x;

            den= N*N;
           printf("%lld: = %lld \n",j,ans);
            //gc= gcd(ans,den);
            //printf("%lld/%lld\n",ans/gc,den/gc);
    }


return 0;
}
