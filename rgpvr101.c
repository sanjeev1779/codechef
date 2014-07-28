#include<iostream>
using namespace std;
#include<math.h>
main()
{
    int i,n,t,sum,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n%2==1)
        {
            k=n/2;
            sum=k*(k+1);
        }
        else
        {
            k=n/2-1;
            sum=n/2+k*(k+1);
        }

        cout<<sum<<endl;

    }

return 0;
}
