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
vector<int>adjM[1004];
int st=0;
int MBP[1004], marked[1004];

/*
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited

            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in the above line, matchR[v]
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 */
int augmentedPath_exists(int x)
{
    int i,y;
    for(i=0;i<adjM[x].size();i++)
    {
        y= adjM[x][i];

        if(marked[y]!=st)// not matched, den go
        {
            marked[y]=st;
            if(MBP[y]<0 || augmentedPath_exists(MBP[y]))
            {
                MBP[y]=x;
                return 1;
            }
        }
    }
    return 0;
}
main()
{
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int test_cases,ans,i,N,nid,x,y;
        S(test_cases);
        while(test_cases--)
        {
            map<int,int>hashMapX, hashMapY;
            S(N);
            while(N--)
            {
                S(x);S(y);
                if( hashMapX.count(x)==0) // x is not present before
                {
                    nid= hashMapX.size();
                    adjM[nid].clear();
                    hashMapX[x]=nid;
                }
                x= hashMapX[x];

                if(hashMapY.count(y)==0)
                {
                    nid= hashMapY.size();
                    hashMapY[y]=nid;
                }
                y= hashMapY[y];
                adjM[x].pb(y);
            }

            // mapping done
            // find the maximum bipartite matching of the given bipartite graph
            memset(marked,-1,sizeof(marked));
            memset(MBP,-1,sizeof(MBP));
            ans=0;
            st=0;
            for(i=0;i<hashMapX.size();i++) // for each x find the MBP of y
            {
                st++;
                if(augmentedPath_exists(i))
                    ans++;
            }
            cout<<ans<<endl;

        }

return 0;
}
