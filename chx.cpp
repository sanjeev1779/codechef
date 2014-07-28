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
    int t,i,j,k;
    cin>>t;
    LL maxm,x;
    int n;
    LL a[2001];
    while(t--)
    {
        S(n);
        maxm=-1;
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    x= a[i]^a[j]^a[k];
                    maxm=max(maxm,x);
                }
            }
        }
        printf("%lld\n",maxm);
    }


return 0;
}

