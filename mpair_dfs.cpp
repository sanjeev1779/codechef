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
int noe=0;
int vis[100005];
vector<int>adj[100005];
void dfs(int i)
{
    int j;
    noe++;
    vis[i]=1;
    for(j=0;j<adj[i].size();j++)
    {
        if(!vis[adj[i][j]])
            dfs(adj[i][j]);
    }
    return;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int N,M,i,x,y;
        S(N)S(M);
        while(M--)
        {
            S(x)S(y)
            adj[x].pb(y);
            adj[y].pb(x);
        }
        LL ans=0;

        for(i=1;i<=N;i++)
        {
            if(vis[i]==0)
            {
                noe=0;
                dfs(i);
                ans+= noe*(N-noe);
            }
        }
        printf("%lld\n",ans/2);
return 0;
}
