#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

double  solve(int arr[][3],int i,int visited,int N,int vis[], double ans,double prob) // arr, N, vis
{
    if(i==N)
       {
            ans=ans+ prob;
            cout<<ans<<" i="<<i<<endl;
            prob=1.0;
       }
    vis[visited]=1;
     if(vis[ arr[i][1]] ==0 && vis[ arr[i][2]]== 0)
    {
        prob= prob*( (double)arr[i][0]/ (double)100.0 );
        solve(arr,i+1,arr[i][1],N,vis,ans,prob);
    }
    if(vis[ arr[i][1]] ==0 && vis[ arr[i][2]]== 1)
    {
        prob= prob*( (double)arr[i][0]/(double)100.0 );
        solve(arr,i+1,arr[i][1],N,vis,ans,prob);
    }
    if(vis[ arr[i][1]] ==1 && vis[ arr[i][2]]== 0)
    {
        prob= prob*(1.0 -(double)arr[i][0]/(double)100.0);
        solve(arr,i+1,arr[i][2],N,vis,ans,prob);
    }
    if( vis[ arr[i][1]] ==1 && vis[ arr[i][2]]==1)
        return ans;
    vis[visited]=0;
}
main()
{
    int i,j,n;
    int arr[52][3];
    int test_cases;
    double ans1,ans;
    int vis[53];
    cin>>test_cases;
    while(test_cases--)
    {
        memset(vis,0,sizeof(vis));
        memset(arr,0,sizeof(arr));
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i][0]; //probability
            cin>>arr[i][1]; //A  ticket number
            cin>>arr[i][2];  // B ticket number
        }
        if(n>16)
            printf("0.000000\n");
        else
        {
            ans1= solve(arr,1,arr[1][1],n,vis,0.0,1.0);
            printf("%.6lf\n",ans1);
        }
    }
return 0;
}

