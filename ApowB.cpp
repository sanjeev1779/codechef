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
LL fast_pow(LL a, int b)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2==1)
            prod= (prod*a);
        a=(a*a);
        b/=2;
    }
    return prod;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int test_cases,b,ch;
      S(test_cases);
      LL n,a;
      double x,y,z;
      while(test_cases--)
      {
            SL(n);
            // n= a^b
            ch=0;
            for(b=2;b<=54;b++)
            {
                x= log2(n)/(1.0*b);
                //cout<<"x= "<<x<<endl;
                a= pow(2,x); // apporximated a
                //cout<<a<<endl;
                if( fast_pow(a,b)==n || fast_pow(a+1,b)==n)
                {
                    ch=1;
                    break;
                }
            }
            if(ch)
                printf("YES\n");
            else printf("NO\n");
      }

return 0;
}
