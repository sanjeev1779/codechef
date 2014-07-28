#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
using namespace std;
main()
{
    int n,x,i,j,d;
    cin>>n;
    int a[n];
    int b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    if(n==2)
    {
        cout<<"2\n";
        cout<<a[0]<<" "<<a[1]<<"\n";
    }
    else if(n==1)
    {
        cout<<"1\n";
        cout<<a[0]<<endl;
    }
    else
    {
            d=a[1]-a[0];
            b[0]=a[0];
            b[1]=a[1];
            j=2;
            x=a[1];
            for(i=1;i<n-1;i++)
            {

                if( (a[i+1]- x ) > d )
                {
                    b[j]=a[i+1];
                    j++;
                    d=a[i+1]-x;
                    x=a[i+1];
                }
            }
             if(j<3)
             {
                 cout<<"3\n";
                    for(i=2;i<n;i++)
                    {
                        if(a[i]-a[1]!=d)
                        {
                            cout<<b[0]<<" "<<b[1]<<" "<<a[i]<<"\n";
                            break;
                        }
                    }
             }
             else
             {
                    cout<<j<<"\n";
                    for(i=0;i<j;i++)
                    {
                        cout<<b[i]<<" ";
                    }
             }
    }
return 0;
}

