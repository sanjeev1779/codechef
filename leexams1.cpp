#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
//int arr[52][3];
int vis[52],a[52][52];
double ans=0.0;
int i,cur_visited,n;
double prob=1.0;
void solve(int i, int cur_visited)
{

    if(i==m-1 && j== m-1)
       {

           ans++;
            cout<<"ans="<<ans<<endl;
       }
    vis[i][j]=1;
    cout<<"i "<<i<<" and  j= "<<j<<endl;
    if( (j+1<m) && vis[i][j+1]==0 && a[i][j+1]==0 )
        solve(i,j+1);
    if( i+1<m && vis[i+1][j]==0 && a[i+1][j]==0 )
        solve(i+1,j);

    if( (j-1>=1) && vis[i][j-1]==0 && a[i][j-1]==0 )
         solve(i,j-1);
    if( (i-1>=1) && vis[i-1][j]==0 && a[i-1][j]==0)
        solve(i-1,j);
    vis[i][j]=0;

}
main()
{
   int j;

    int test_cases;
    double ans1,ans;

    cin>>test_cases;
    while(test_cases--)
    {
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        cin>>n;
        for(j=1;j<=n;j++)
        {
            cin>>a[j][0]; //probability
            cin>>a[j][1]; //A  ticket number
            cin>>a[j][2];  // B ticket number
        }
         ans= 0.0;
        if(n>16)
            printf("0.000000\n");
        else
        {
            solve(1,50);
            printf("%.6lf\n",ans);

        }
    }
return 0;
}

