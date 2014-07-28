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
    int n,m;
    S(n);
    S(m);
    int a[m+2];
    int i;
    for(i=0;i<m;i++)
        S(a[i]);
    int st=1;
    LL ans=0;
    for(i=0;i<m;i++)
    {
        if(a[i]>=st)
        {
            ans+=a[i]-st;
            st=a[i];
        }
        else
        {
            ans+=n+(a[i]-st);
            st=a[i];
        }
    }
    cout<<ans<<endl;
return 0;
}
