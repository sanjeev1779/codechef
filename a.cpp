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
    int n;
    LL x,y;
    S(n);
    pair<LL,LL>p[n+1];
    for(i=0;i<n;i++)
    {
        SL(x); SL(y);
        p[i]=make_pair(x,y);
    }
    sort(p,p+n);

return 0;
}
