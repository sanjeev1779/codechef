#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
main()
{
    int i,n,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for(i=0;i<n;i++)
        cout<<v[i]<<endl;

return 0;
}
