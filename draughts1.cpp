#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stack>
#include<vector>
#define pb push_back
using namespace std;
int visited[50010];
int win[50005];
vector<int>adj[50005];
vector<int>comp[50005];
int c=0,flag=0;
int cnt[50005];
long long int temp;
 int N,M,K,i,x,y,s,j,node,l,te,t,v,kk;
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

void dfs(int node)
{
    visited[node]=1;
    comp[c].push_back(node);
    if(win[node]==1)
        cnt[c]++;
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
             dfs(adj[node][i]);
    }
    return;
}
void dfs2(int node)
{
    visited[node]=1;
   // cout<<"in dfs "<<node<<endl;
    if(win[node]==1) // draught
    {
       // cout<<"windows 1 "<<node<<endl;
        flag=1; return;
    }
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
              dfs(adj[node][i]);
    }
    return;
}
main()
{
  // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
    memset(visited,0,sizeof(visited));
//    memset(cnt,0,sizeof(cnt));

    long long int pairs,sum=0;
   // scanf("%d %d",&N,&M
            N= fastRead_int();
            M=fastRead_int();

    for(i=1;i<=N;i++)
    {
        //scanf("%d",&win[i]);
        win[i]=fastRead_int();
    }
    while(M--)
    {
       // scanf("%d %d",&x,&y);
       x= fastRead_int();
       y= fastRead_int();
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(i=1;i<=N;i++)
    {
        if(visited[i]==0)
        {
            cnt[c]=0;
            dfs(i);
            temp= cnt[c];
            pairs= (temp*(temp-1))/2;
            sum+= pairs;
            c++;
        }
    }
    //end of 1st answer
    // number of connected components in the forest = c;
   // cout<<"first "<<sum<<endl;
    int rubik=0;
   // cout<<"connected "<<c<<endl;
    for(i=0;i<=c;i++) // for all trees
    {
        if(cnt[i]<=1) continue; // if it has less than 2 windows, no draught
        l=comp[i].size();
       // cout<<"l= "<<l<<endl;
        for(j=0;j<l;j++) // for all nodes of the tree
        {
            node= comp[i][j];
            if(win[node]==1) rubik++;
            else // for 0
            {
                te= adj[node].size();
                //cout<<"size of "<<node<<" = "<<te<<endl;
                t=0;
                // removes backtrack
                memset(visited,0,sizeof(visited));
                 visited[node]=1;
                for(kk=0;kk<te;kk++)
                {
                    v= adj[node][kk];
                   // cout<<v<<endl;
                    flag=0;
                    dfs2(v);
                   // cout<<"after flag "<<flag<<endl;
                    if(flag==1)
                        t++;
                    if(t==2)break;
                }
                if(t>=2) rubik++; // at least 2 ones found on 2 different sides
            }
        }
    }
    printf("%lld %d\n",sum,rubik);
    return 0;
}
