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
using namespace std;
LL BIT[10005];
int N;
void update(int idx,int val)
{
    while(idx<=N)
    {
        BIT[idx]+=val;
        idx+= (idx&-idx);
        //cout<<"hi  "<<idx<<endl;
    }
}

LL read(int idx)
{
    LL sum=0;
    while(idx>0)
    {
        sum+= BIT[idx];
        idx-= (idx&-idx);
    }
    return sum;
}

int main()
{
     freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
       int t,u,val,l,r,q,idx;
       S(t);
       LL left,right,ans;
       while(t--)
       {
           memset(BIT,0,sizeof(BIT));
            S(N);S(u);
            while(u--)
            {
                scanf("%d %d %d",&l,&r,&val);l++;r++;
                update(l,val);
                update(r+1,-val);
            }
            for(int i=1;i<=N;i++)
            {
                cout<<read(i)<<endl;
            }
            cout<<endl;
            S(q);
            while(q--)
            {
                scanf("%d",&idx);idx++;
                ans= read(idx);
                printf("%lld\n",ans);
            }
       }
return 0;
}
