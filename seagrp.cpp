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
int bpGraph[102][102];
int N,M;
int bpm(int u, int visited[], int maxm_bipartite_match[])
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (bpGraph[u][i] && !visited[i])
        {
            visited[i] = 1;
            if (maxm_bipartite_match[i] ==-1 || bpm(bpGraph, maxm_bipartite_match[i], visited, maxm_bipartite_match))
            {
                maxm_bipartite_match[i] = u;
                return 1;
            }
        }
    }
    return 0;
}
int maxBPM()
{
    int maxm_bipartite_match[N];
    memset(maxm_bipartite_match, -1, sizeof(maxm_bipartite_match));
    int matching = 0;
    for (int u = 0; u < M; u++)
    {
        bool visited[N];
        memset(visited, 0, sizeof(visited));
        if (bpm(bpGraph, u, visited, maxm_bipartite_match))
            matching++;
    }
    return matching;
}
main()
{
    // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);

    int test_cases,i,x,y;
    S(test_cases);
    while(test_cases--)
    {
        S(N) S(M)
        memset(adj,0,sizeof(adj));
        for(i=1;i<=M;i++)
        {
            S(x) S(y);
            adj[x][y]=1;
            adj[y][x]=1;
        }
        cout << "Maximum number of applicants that can get job is "
             << maxBPM();
    }
    return 0;
}
