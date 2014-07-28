#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define mod 1000000007
using namespace std;
main()
{
 int test_cases;
 cin>>test_cases;
 LL a[3];
 LL ans;
 while(test_cases--)
 {
     cin>>a[0]>>a[1]>>a[2];
     sort(a,a+3);
     ans=  ((( (a[0]%mod)* ((a[1]-1)%mod))%mod)*((a[2]-2)%mod) )%mod;
     cout<<ans<<endl;

 }

return 0;
}

