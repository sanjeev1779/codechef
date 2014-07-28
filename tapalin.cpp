#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

main()
{
    int test_cases,ans,num;
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>num;
        num=ceil(float(num)/float(2));
        cout<<num<<endl;
        ans=pow(26,num);
        cout<<ans<<endl;
    }

return 0;
}
