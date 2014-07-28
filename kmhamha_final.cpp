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
vector<int>adjM[1003];
int marked[1003], MBP[1003];
int st=0;
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
int augmentedPath_exists(int i)
{
    int y,j;
    for(j=0;j<adjM[i].size();j++) // for each x=i check for y=j
    {
        y= adjM[i][j];
        if(marked[y]==st)
            continue;

            marked[y]=st;
            if(MBP[y]== -1 || augmentedPath_exists(MBP[y]))
            {
                MBP[y]=i;
                return 1;
            }

    }
    return 0;
}
main()
{
        freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int test_cases,newid;
        S(test_cases);
        int N,i,x,y;
        while(test_cases--)
        {
            map<int,int>hashX,hashY;
            S(N);
            while(N--)
            {
                S(x); S(y);

                if(hashX.count(x)==0)
                {
                    newid= hashX.size();
                    adjM[newid].clear();
                    hashX[x]=newid;
                }
                x= hashX[x];

                // similarly map Y cordi
                if(hashY.count(y)==0)
                {
                    newid= hashY.size();
                    hashY[y]= newid;
                }
                y= hashY[y];

                adjM[x].pb(y);
            }
            int maxmMatch=0;
            st=0;
            memset(MBP,-1,sizeof(MBP));
            memset(marked,-1,sizeof(marked));
            for(i=0;i<hashX.size();i++)
            {
                st++;
                if(augmentedPath_exists(i))
                    maxmMatch++;
            }
            cout<<maxmMatch<<endl;
        }

return 0;
}
