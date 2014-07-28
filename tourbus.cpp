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
vector<int>adj[55];
vector<int>ans[30000];
main()
{
        //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int N,i,j,node1=0,node2=0,pos1=0,pos2=0,x,y;
        S(N);
        int a[N+2][2];
        for(i=0;i<N;i++)
        {
           cin>>x>>y; // x and y
        }
        string str;
        for(i=0;i<N;i++)
        {
            cin>>str;
            for(j=0;j<N;j++)
            {
                if(str[j]=='Y')
                {
                    adj[i].pb(j); // adjcency list
                }
            }
        }

        int K=0;
        for(i=0;i<N;i++)
        {
            //for(j=0;j<adj[i].size();j++)
            while(adj[i].size()>0)
            {
                //cout<<" node = "<<i<<" and size= "<<adj[i].size()<<endl;
                if(adj[i].size()>=2)
                {
                    node1= adj[i][0];
                    node2= adj[i][1];
                    //cout<<node1<<" "<<node2<<" "<<K<<endl;
                    ans[K].pb(node1);
                    ans[K].pb(i);
                    ans[K].pb(node2);
                    //cout<<"b4 deleted\n";
                    //cout<<"node to be deletd= "<<adj[i][0]<<endl;
                    adj[i].erase(adj[i].begin()); // link from i to node 1 is deleted
                    adj[i].erase(adj[i].begin());  // link from i to node 2 is deleted
                   // cout<<"deleted\n";
                    for(x=0;x<adj[node1].size();x++)
                    {
                        if(adj[node1][x]==i)
                            pos1=x;
                    }
                    for(x=0;x<adj[node2].size();x++)
                    {
                        if(adj[node1][x]==i)
                            pos2=x;
                    }
                    if(pos1<=adj[node1].size()-1);
                        adj[node1].erase( adj[node1].begin()+pos1);  // link from node1 to i is deleted
                    if(pos2<=adj[node2].size()-1);
                    adj[node2].erase( adj[node2].begin()+pos2);   // link from node2 to i is deleted
                    K++;
                  //  cout<<" k in the end "<<K<<endl;
                }
                else if(adj[i].size()==1)
                {

                    node1= adj[i][0];
                    ans[K].pb(node1);
                  //  cout<<node1<<" "<<K<<endl;
                    ans[K].pb(i); // node i to node1
                    K++;
                    adj[i].erase(adj[i].begin()+0); // link from i to node 1 is deleted

                     for(x=0;x<adj[node1].size();x++)
                    {
                        if(adj[node1][x]==i)
                            pos1=x;
                    }
                    if(pos1<=adj[node1].size()-1);
                        adj[node1].erase( adj[node1].begin()+pos1);  // link from node1 to i is deleted
                }
            }
        }
        cout<<K<<endl;
        for(i=0;i<K;i++)
        {
            printf("%d ",ans[i].size());
            for(j=0;j<ans[i].size();j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
return 0;
}
