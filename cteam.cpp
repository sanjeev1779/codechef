#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
#define inf 1000000001
#define mp make_pair
using namespace std;
main()
{
    int N;
    cin>>N;
    LL A[N+2],R[N+2];
    pair<LL,LL>ar[N+2];
    LL sum1;
    LL sum2;
    LL maxm1=0,maxm2=0;
    LL minm1=inf,minm2=inf;
    LL ans1=0,ans2=0;
    scanf("%lld %lld",&A[0],&R[0]);
    LL maxm1=A[0],maxm2=0;
    LL minm1=A[0],minm2=inf;
    cout<<R[0]<<endl;
    for(i=2;i<=N;i++)
    {
        //cin>>A[i]>>R[i];
        scanf("%lld %lld",&A[i],&R[i]);

        ar[i]= mp(A[i],R[i]);

        if(i%2==1)
        {
            maxm1= max(maxm1,Ar[i].first);
           if(Ar[i].first<minm)
           {
               ans1 = ans1+ Ar[i].second- Ar[i].;
           }

            maxm2= max(maxm2,Ar[i].first);
            minm2 = min(minm2, Ar[i].first);
            ans1 = ans1 + Ar[i].second;
            ans2=
            ans= abs(ans1-ans2);
        }
        else
        {
           maxm1= max(maxm1,Ar[i].first);
            minm1 = min(minm1, Ar[i].first);

            maxm2= max(maxm2,Ar[i].first);
            minm2 = min(minm2, Ar[i].first);
            ans1 = ans1 + Ar[i].second;

            ans= abs(ans1-ans2);
        }
        cout<<ans<<endl;

    }

return 0;
}
