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
#include<climits>
#define mp make_pair
using namespace std;
main()
{
    int n,k,i,j,minm_val;
    cin>>n>>k;
    int a[n+5];
    LL ans;
    int fu;
    for(i=0;i<n;i++)
    {
        S(a[i]);
    }
    minm_val= INT_MAX;
    for(i=0;i<k;i++)
    {
        ans=0;
        for(j=i;j<n;j=j+k)
        {
            ans= ans+a[j];
        }

        if(ans<minm_val)
        {
            minm_val=ans;
            fu=i+1;

        }
    }
    cout<<fu<<endl;

return 0;
}
