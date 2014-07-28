#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
#define traverse_map(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;

int N;
void update(LL val, int idx)
{
    while(idx<=N)
    {
        tree[idx]+=val;
        idx=idx+(idx&-idx);
    }
}

LL query(int idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx=idx-(idx&-idx);
    }
    return sum;
}
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int i,j,no,x1;
        LL K,x,y,data;
        LL ans=0;
        cin>>N>>K;
        LL sum[N+2];
        sum[0]=0;
        for(i=1;i<=N;i++)
        {
            scanf("%lld",&data);
            data-=K;
            sum[i]=sum[i-1]+data;
        }
        printf("%lld\n",ans);
return 0;
}
