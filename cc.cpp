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
#define pb push_back
#define mp make_pair
using namespace std;
int parent[100005];
int find(int v)
{
    if(v==parent[v])
        return v;
    else
        return find(parent[v]);
}
main()
{
    int t,i,cnt,x,y,n,e,root1,root2;
    cin>>t;
    while(t--)
    {
        S(n);S(e);

        for(i=0;i<n;i++)
            parent[i]=i;
        while(e--)
        {
            S(x);S(y);
            root1= find(x);
            root2= find(y);
            parent[root2]=root1;
        }
        cnt=0;
        for(i=0;i<n;i++)
        {
            if(parent[i]==i)
                cnt++;
        }
        P(cnt);
    }


return 0;
}
