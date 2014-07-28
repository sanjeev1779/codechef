#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;
int visited[10010];
int win[10005];
vector<int>adj[10005];
vector<int>comp[10005];
int c=0;
int cnt=0;
void dfs(int node)
{
    visited[node]=1;
    cout<<node<<" ";
    if(adj[node].size()==1)
        printf("child \n");
    comp[c].push_back(node);
    if(win[node]==1)
        cnt++;
    for(int i=0;i<adj[node].size();i++)
    {
        if(visited[adj[node][i]]==0)
             dfs(adj[node][i]);
    }
    return;
}
main()
{
    freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
    memset(visited,0,sizeof(visited));
    int N,M,K,pairs,i,x,y,s,j,node,flag;
    scanf("%d %d",&N,&M);

    for(i=1;i<=N;i++)
    {
        scanf("%d",&win[i]);
    }

    while(M--)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int sum=0;
    for(i=1;i<=N;i++)
    {
        if(visited[i]==0)
        {
            cnt=0;
            dfs(i);
            pairs= (cnt*(cnt-1))/2;
            sum+= pairs;
            c++;
        }
    }
    printf("%d ",sum);
    //end of 1st answer
    // number of connected components in the forest = c;

    for(i=0;i<c;i++)
    {
        while(1)
        {
            flag=0;
            s=comp[i].size();
            for(j=0;j<s;j++)
            {
                node= comp[i][j];
                if(adj[node].size()==1 && win[node]==0) // child node and it is zero
                {
                    flag=1;
                }
            }
            if(flag==0) break;

        }
    }





    return 0;
}
