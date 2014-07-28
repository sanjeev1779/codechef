#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int N,i,j;
    S(N);
    int a[N+2];
    for(i=0;i<N;i++)
        S(a[i]);
        int p=0;
    for(i=0;i<=N-3;i++)
    {
        for(j=i+1;j<=N-2;j++)
        {
            int maximum1= max(a[i],a[i+1]);
            int minm1= min(a[i],a[i+1]);
            int maxm2= max(a[j],a[j+1]);
            int minm2= min(a[j],a[j+1]);
            if(minm1<minm2 && maximum1>minm2 && maxm2>maximum1)
                {

                    p=1;
            break;
                }

        }
        if(p==1)
            break;
    }
    if(p)
        cout<<"yes\n";
    else cout<<"no\n";

return 0;
}
