#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define sc(n) scanf("%d",&n);
#define LL long long
#define max_val 1<<17
const int maxm = 100000;
vector <int>sup[maxm+1];
int begin[maxm+1];
int end[maxm+1];
using namespace std;


//make Binary index tree for query and updating the skills of the warriors
//BIT data structure is used here for storing skills and summing the skills at that index

struct Binary_index_tree
{
    int val[max_val];
    void fillit()
    {
        memset(val,0,sizeof(val));
    }
    void update(int pos,int up)
    {
        while(idx<=max_val)
        {
            val[pos]= up;
            pos=pos+ (pos &-pos);
        }
    }
    int query(int idx)
    {
        int sum=0;
        while(idx>0)
        {
            sum=sum+val[idx];
            idx=idx-(idx & -idx);
        }
        return sum;
    }
}BIT; // make a adt of Binary_index_tree

void dfs(int u,int p)
{
    assert(dfsno[u]==0);
    dfsno[u]= ++visited;
    int l= sup[u].size();
    for(int i=0;i<l;i++)
    {
        if(sup[u][i]!=p)
        {
            dfs(sup[u][i],u);
        }
    }
    begin[u]= dfsno[u];
    end[u]= visited;
}
main()
{
    int N,M,u,v;
    scanf("%d %d",&N,&M);
    int skill[N+1];


    for(i=1;i<=N;i++)
    {
        scanf("%d",&skill[i]);
    }
    for(i=0;i<N-1;i++)
    {
        scanf("%d %d",&u,&v);
        sup[u].push_back(v);
        sup[v].push_back(u);
    }
return 0;
}

