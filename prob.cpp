#include<iostream>
#include<stdio.h>
#define LL long long
using namespace std;
main()
{
    int t;
    scanf("%d",&t);
    LL T1,T2,T3,T4;
    double ans=0.0;

    while(t--)
    {
        scanf("%lld %lld %lld %lld", &T1,&T2,&T3,&T4 );
        ans= (double)T1/ (double)(T1+T2);
        cout<<ans<<endl;
    }
return 0;
}
