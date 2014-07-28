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
main()
{
    int t;
    S(t);
    double a,p,q,sum,numer,denom,num;
    int D;
    int i;
    while(t--)
    {
        cin>>a>>p>>q>>D;
        // sum of agp= a/(1-r) + d*r/(1-r)**2
        //sum= p/(1.0-a) + q*a*1.0/ ((1-a)*(1-a)) - p;
        numer= p*(1.0-a) + q*a- p*(1.0-a)*(1.0-a);
        denom= (1-a)*(1-a);
        int a[D+2];
        printf("%d",numer/denom);
        for(i=0;i<D;i++)
            {
                num=numer*10;
                a[i]=num/denom;
                printf("%d",num/denom);
                numer=num%denom;
            }
       // printf("%.%d lf\n",D,sum);
       cout<<sum<<endl;
    }
return 0;
}
