#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
main()
{
    int n,i,ans;
    int a[100001];
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
        if(n%2==0)
            ans=n/2;
        else
            ans=n/2+1;

    cout<<ans<<endl;
    for(i=1;i<=ans;i++)
    {
        cout<<i<<" "<<ans<<endl;
    }

return 0;
}
