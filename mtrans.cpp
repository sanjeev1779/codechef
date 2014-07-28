#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
    int t,i,j,R,C;
    cin>>t;
    int a[11][11];
    while(t--)
    {
        cin>>R>>C;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
               {
                   cin>>
                   cin>>a[i][j];
               }
        }
        for(i=0;i<C;i++)
        {
            for(j=0;j<R;j++)
                cout<<a[j][i]<<" ";
            cout<<"\n";
        }
    }

return 0;
}
