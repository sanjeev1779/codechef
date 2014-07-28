#include<iostream>
#include<stdio.h>
using namespace std;
int i;
int combination(int a[], int sum,int N)
{
    int no_of_combo = 1;
    for(i=0;i<N;i++)
    {
        if( (sum-a[i])>= sum )
        {
            a[i]=0;
            no_of_combo+= combination(a,sum,N);
        }
    }
    return no_of_combo;
}
main()
{
 int N;
 cin>>N;
 int a[N];
 int sum=0;
 for(i=0;i<N;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    int ans= combination(a,sum,N);
    cout<<ans<<endl;

return 0;
}
