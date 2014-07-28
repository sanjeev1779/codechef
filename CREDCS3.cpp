#include<stdio.h>
#include<iostream>
#define LL long long
using namespace std;
main()
{
    int t;
    cin>>t;
    LL i;
    int n;
    LL a[101]={0};
    a[1]=1;
    for(i=2;i<=100;i++)
    {
        a[i]= (a[i-1]*(2*i-1))%1000000007;
    }
    while(t--)
    {
        cin>>n;
        cout<<a[n]<<endl;
    }

return 0;
}
