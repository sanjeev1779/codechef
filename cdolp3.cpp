#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
int arr[1000001]={0};
int i;
void precompute()
{
    arr[2]=2; //  = 2/2+(1-1)=2
    arr[3]=2; //  = 3/3+(1-1)=2
    for(i=4;i<=1000000;i++)
    {
        arr[i]=arr[i-1]+1;
        if(i%2==0)
            arr[i]= min(arr[i],1+arr[i/2]);
        if(i%3==0)
            arr[i]= min(arr[i],1+arr[i/3]);

    }
}
main()
{
    precompute();
    int t;
    cin>>t;
    int ans,n;
    while(t--)
    {

        cin>>n;
        cout<<arr[n]<<endl;
    }

return 0;
}
