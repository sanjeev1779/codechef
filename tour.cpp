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
main()
{
         freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int N,x,i,j,K,y,first,second,flag;
       S(N);
       for(i=0;i<N;i++)
       {
           cin>>x>>y;
       }
       string str;
       int m= N*N+N;
       vector<int>ans[m];
       int a[55][55];
       int degree[55],l;
       int edges=0;
       memset(degree,0,sizeof(degree));
       for(i=0;i<N;i++)
       {
           cin>>str;
           l= str.size();
           for(j=0;j<l;j++)
           {
               if(str[j]=='Y')
               {
                    a[i][j]=1;
                    degree[i]++;
		    edges++;
               }
               else a[i][j]=0;
           }
       }
     /*  for(i=0;i<N;i++)
       {
           //cout<<" "<<i<<"  ";
           for(j=0;j<N;j++)
           {
               //if(a[i][j])
                cout<<a[i][j]<<" ";
           }
           cout<<endl;
       }*/
//cout<<edges<<endl;
   edges/=2;
       K=0;
	int vis[55];
 memset(vis,0,sizeof(vis));
       for(i=0;i<N;i++)
	{
		first=i;
		second=-1;
		for(j=0;j<N;j++)
		{
			if(a[i][j]==1 )
			{
				second=j; break;
			}
		}
		if(second== -1) continue; // unconnected
		ans[K].pb(first);
		ans[K].pb(second);
		a[first][second]=0;//delete edges
		a[second][first]=0;
		edges--;
		vis[first]=1;
		vis[second]=1;
		while(1)
		{
			flag=0;
			for(j=0;j<N;j++)
			{
				if(a[second][j]==1 && vis[j]==0)
                {
                    flag=1;
                    vis[j]=1;
					a[second][j]=0, a[j][second]=0; second=j; ans[K].pb(j);  edges--;  break;

				}
			}
			if(flag==0) {  memset(vis,0,sizeof(vis)); K++; break;}
		}
	}
	 vector<int>vec;
       for(i=0;i<N;i++)
       {
          // cout<<" degree= "<<degree[i]<<endl;
           for(j=0;j<N;j++)
           {
                if(a[i][j]==1)
                {
                    vec.pb(j);
                    a[i][j]=0;
                    a[j][i]=0;
                }
                if(vec.size()==2)
                {
                    ans[K].pb(vec[0]);
                    ans[K].pb(i);
                    ans[K].pb(vec[1]);
                  //  cout<<K<<" and "<<vec[0]<<" "<<i<<" "<<vec[1]<<endl;
                    vec.clear();
                    K++;
                }
           }
           if(vec.size()==1)
           {
                ans[K].pb(i);
                ans[K].pb(vec[0]);
                 //cout<<K<<" and "<<vec[0]<<" "<<i<<endl;
               vec.clear();
               K++;
           }
       }
        cout<<K<<endl;
        for(i=0;i<K;i++)
        {
            cout<<ans[i].size()-1<<" ";
            for(j=0;j<ans[i].size();j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
return 0;
}
