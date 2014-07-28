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
int nodes;
vector<int> adj[100005];
int visited[100005];
void dfs(int x)
{
    nodes++;
    visited[x]=1;
    int siz=adj[x].size();
    for(int i=0;i<siz;i++)
    {
        if(visited[adj[x][i]]==0)
            dfs(adj[x][i]);
    }
}
main()
{
    //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int t=1;
      while(t--)
      {
          int n,m,x,y;
          LL ans=0;
          S(n);
          S(m);
            int conn_comp=0;
          for(int i=0;i<m;i++)
          {
              S(x);S(y);
              adj[x].pb(y);adj[y].pb(x);
          }

          memset(visited,0,sizeof(visited));
          if(m==n-1)
          {


          for(int i= 1;i<=n;i++)
          {
            if(visited[i]==0)
              {
                  nodes=0;conn_comp++;
                  dfs(i);
                //cout<<nodes<<endl;
                  ans+=(nodes*(n-nodes));
              }

          }


          if(conn_comp!=1)
            cout<<"NO";
          else
            cout<<"YES";
          }
          else
            cout<<"NO";
      }
return 0;
}
