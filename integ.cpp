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
    int N;
    LL a,i,X,first;
    S(N);
    LL x;
    LL ans=0,neg_sum=0;
    vector<LL>vec;
    for(i=0;i<N;i++)
    {
        scanf("%lld",&a);
        if(a<0)
        {
            vec.pb(a);
            neg_sum+=a;
        }
    }
    printf("%lld\n",neg_sum);
    neg_sum= -neg_sum;
    printf("%lld\n",neg_sum);
    scanf("%lld",&X);
    sort(vec.begin(),vec.end());
    int l= vec.size();
    LL cnt=0;
    while(l>0)
    {
        if(l>=X)
        {
            first = -vec[l-1];
            ans+= first*X;
            neg_sum=neg_sum-l*first;
            cnt=cnt+first;
            vec.erase(vec.begin()+l-1);
            if(l>=2)vec[l-2]+=cnt;
        }
        else
        {
            ans=ans+neg_sum;
            break;
        }
        l=vec.size();
    }
    printf("%lld\n",ans);

return 0;
}
