#include<stdio.h>
#include<iostream>
using namespace std;

int repath[10][10],a[10][10],ans=0,m;

void solve(int i, int j)
{


    if(i==m-1 && j== m-1)
       {

           ans++;
       }
    repath[i][j]=1;
    if( (j+1<m) && repath[i][j+1]==0 && a[i][j+1]==0 )
        solve(i,j+1);
    if( i+1<m && repath[i+1][j]==0 && a[i+1][j]==0 )
        solve(i+1,j);

    if( (j-1>=1) && repath[i][j-1]==0 && a[i][j-1]==0 )
         solve(i,j-1);
    if( (i-1>=1) && repath[i-1][j]==0 && a[i-1][j]==0)
        solve(i-1,j);
    repath[i][j]=0;

}
main()
{
    int i,j;
    cin>>m;

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
           cin>>a[i][j];
           repath[i][j]=0;
        }
    }

        solve(0,0);
        cout<<ans<<endl;
return 0;
}

