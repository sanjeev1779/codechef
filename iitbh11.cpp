#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int t,ans,i,j,n;
    cin>>t;
    int x;
    for(x=1;x<=t;x++)
    {
        cin>>n;
        int a[n],b[n];
        ans=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);//inc
        sort(b,b+n);//inc
        j=n-1;
        for(i=0;i<n;i++)
        {
            ans=ans+a[i]*b[j];
            j--;
        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }

return 0;
}
