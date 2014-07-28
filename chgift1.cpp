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
    int prod;
    int ans,neg;
    int x1;
    int minm;
    int a[13];
    while(t--)
    {
        S(n);
        prod=1;
        neg=0;
        for(i=0;i<n;i++)
        {
            S(a[i]);
            if(a[i]<0)
                neg++;
        }
        if(neg%2)
        {

            for(i=0;i<n;i++)
            {
                if(a[i])
                    prod*=a[i];
            }
            P(prod);
        }
        else
        {
                ans=a[0];
                for(i=1;i<n;i++){
                    ans= min(a[i]*ans, min(ans-a[i],ans+a[i]));
                }
            P(ans);
        }
    }

return 0;
}
