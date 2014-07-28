#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
inline int fastRead_int()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};

vector<int>adj[100005];
int vis[100005]={0};
int minm= 100005;
int cost[100005];
void dfs(int v)
{
    int j;
    vis[v]=1; // make true
    if(cost[v]>=0 && cost[v]<=minm)
        minm= cost[v];
    for(j=0;j<adj[v].size();j++)
    {
        if(!vis[adj[v][j]]) // unvisited
        {
            dfs( adj[v][j]);
        }
    }
    return;
}
main()
{
          //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int N,M,x,y,i;
        N= fastRead_int();
        M= fastRead_int();
        while(M--)
        {
            x= fastRead_int();
            y= fastRead_int();
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for(i=1;i<=N;i++)
           cost[i]= fastRead_int();

        LL connected=0;
        int ch=0;
        int minm_of_all= 100005;
        LL total_minm_sum=0,ans;
        for(i=1;i<=N;i++)
        {
            if(vis[i]==0)
            {
                minm=100005;
                connected++;
                dfs(i);
               // cout<<" minm = "<<minm<<endl;
                if(minm==100005)
                {
                    ch=1;
                    break;
                }
                else
                {
                        total_minm_sum+= minm;
                        minm_of_all= min(minm_of_all,minm);
                }
            }
        }
       // cout<<"connected= "<<connected<<endl;
       if(connected==1)
            printf("0\n");
        else if(ch==1)
            printf("-1\n");
        else
        {
            ans= total_minm_sum+(connected-2)*minm_of_all;
            printf("%d\n",ans);
        }
return 0;
}
