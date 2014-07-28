#include<stdio.h>
#include<iostream>
using namespace std;
main()
{
    int n,d12,i,j,k;
    cin>>n;
    int a[n];
    int b[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    d12=a[1]-a[0];
    b[0]=a[0];
    b[1]=a[1];
    j=1;
    for(i=2;i<n;i++)
    {
        int flag=1;
        for(k=j;k>=0;k--)
        {
            if(a[i]-b[k]==d12)
            {
                flag=0;
            }
            if(flag==0)
                break;
        }
        if(flag==1)
        {
            j++;
            b[j]=a[i];
        }
    }

    cout<<j<<endl;
    for(i=0;i<j;i++)
    {
        cout<<b[i]<<" ";
    }
return 0;
}
