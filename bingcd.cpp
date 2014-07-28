#include<iostream>
using namespace std;
main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long int n,a=2;
        cin>>n;
        while(n%2==0)
        {
            a*=2;
            n/=2;
        }
        cout<<a<<"\n";
    }

return 0;
}
