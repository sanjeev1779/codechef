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
int n;
int visited[102];
vector<int>adj[102];
int matchedPair[102];
int bpm(int node)
{
    int cur_node=0;
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
        cur_node= adj[node][i];
        if(visited[cur_node]) continue;
        visited[cur_node]=1;
        if(matchedPair[cur_node]<0 || bpm(matchedPair[cur_node]) )
            {

                matchedPair[cur_node]= node;
                matchedPair[node]= cur_node;
                return 1;
            }
    }
    return 0;
}
main()
{
        //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int x,y,i,t,m,tot_matched;
    S(t);
    while(t--)
    {
        for(i=0;i<102;i++) adj[i].clear();
        memset(visited,0,sizeof(visited));
        memset(matchedPair,-1,sizeof(matchedPair));
        S(n); S(m); S(P);
        while(P--)
        {
            S(x) S(y)
            adj[x].pb(y);
            adj[y].pb(x);
        }
        if(n%2)
        {
            printf("NO\n");
        }
        else
        {
            tot_matched=0;
            for(i=1;i<=n;i++)
            {
                if(matchedPair[i]!=-1) continue; // already matched;
                memset(visited,0,sizeof(visited));
                tot_matched+=bpm(i);
            }
           // cout<<tot_matched<<endl;
            if(tot_matched==n/2)
                printf("YES\n");
            else printf("NO\n");
        }
    }
return 0;
}
