#include<iostream>
using namespace std;
main()
{
    int n,t,i,j,ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;

        for(i=1;i<=n-1;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if((i*j) % (i+j)==0)
                ans++;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}
