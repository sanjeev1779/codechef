#include<iostream>
#include<map>                                                      //
#include<functional>
#include<string>
#include<cstring>
#include<bitset>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<stack>
#include<cstdio>
#include<ctime>

using namespace std;
#define gc getchar_unlocked
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,n) for(int i=(0);i<(n);i++)
#define CLEAR(a) memset((a),0,sizeof(a))
#define pb push_back
#define ll long long int
#define md 1000000007
#define swap(a,b) Swap(&a,&b)
#define bigger(a,b) {a>b?a:b}
#define smaller(a,b) {a<b?a:b}
int check[25][25],matrix[25][20060];
int m,n;
int power(int a,int b)
    {
        int ans=1;
            while(b>0)
            {
                if(b%2==1)
                   ans= (a*ans);
                a= (a*a);
                b/=2;
            }
            return ans;
    }
void powersetgeeksforgeeks()
{
        memset(check,0,sizeof(check));
        memset(matrix,0,sizeof(matrix));

        int s[22];
        int ch,ans=-1;
        for(int i=0;i<n;i++)
        	s[i]=i+1;
        int pset=power(2,n);
       // cout<<pset;

        for(int i = 0; i <pset; i++)
        {
           vector<int>v;
            ch=0;
           for(int j = 0; j < n; j++)
           {
	          if(i&(1<<j))
	          {
	              int l=v.size();
	          	  for(int k=0;k<l;k++)
	          	  {

	          	  	if(matrix[v[k]][s[j]]==1)
                        {
                            ch=1;break;
                        }
	          	  }
	          	  v.pb(s[j]);
                }
           }
           if(ch==0)
           {
               int p=v.size();
               ans= max(ans,p);
           }
        }
			printf("%d\n",ans);
}


main()
{

    int dummy,temp;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        for(int j=1;j<=temp;j++)
        {
            cin>>dummy;
            matrix[i][dummy]=1;
        }
    }
    for(int i=1;i<=n;i++)
      {for(int j=1;j<=m;j++)
        {if(matrix[i][j]==1)
            {for(int k=1;k<=n;k++)
                {if( i!=k && matrix[k][j]==1)
                            check[i][k]=1;
        }}}}

    /*
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cout<<matrix[i][j];


    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cout<<check[i][j];
    */
    powersetgeeksforgeeks();
return 0;
}
