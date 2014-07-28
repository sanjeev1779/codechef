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
main()
{
    int t;
    S(t);
    int n,i;
    int prod,flag;
    LL ans;
    int x1;
    LL minm;
    LL a[13];
    while(t--)
    {
        S(n);
        prod=1;
        flag=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]<0)
                flag=1;
        }


        if(flag==0){
        ans=a[0];
        for(i=1;i<n;i++){
            ans= min(a[i]*ans, min( ans-a[i],ans+a[i] ));
        }


        cout<<ans<<endl;
        }
        else
        {
            if(n==1)
        {
            P(a[0]);
        }
        minm=100;
        if(n==2)
        {
            minm=min(a[0]-a[1],minm);
            minm=min(a[0]+a[1],minm);
            minm=min(a[0]*a[1],minm);
            P(minm);
        }
        minm=100;
        if(n==3)
        {
            minm= min(a[0]+a[1]+a[2],minm);
           // P(minm);
            minm= min(a[0]+a[1]-a[2],minm);
           // P(minm);
            minm= min((a[0]+a[1])*a[2],minm);

            minm= min((a[0]-a[1])+a[2],minm);

            minm= min((a[0]-a[1])-a[2],minm);

            minm= min((a[0]-a[1])*a[2],minm);

            minm= min((a[0]*a[1])-a[2],minm);

            minm= min((a[0]*a[1])+a[2],minm);

            minm= min((a[0]*a[1])*a[2],minm);
            P(minm);
        }
        if(n>3)
            printf("0\n");
        }
    }

return 0;
}
