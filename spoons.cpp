#include<stdio.h>
#include<iostream>
#include<math.h>
#define LL unsigned long long
using namespace std;
main()
{
    int T;
    cin>>T;
    LL n;
    LL ans;
    while(T--)
    {
        cin>>n;
        if(n==2)
            cout<<n<<endl;
        else {
        ans= ceil((1.0 + sqrt(1.0 + 8.0*n))/2.0);
       cout<<ans<<endl;
        }
    }
return 0;
}
