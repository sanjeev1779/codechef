

#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
using namespace std;
main()
{
    int t;
	LL c,d;
	cin>>t;
	LL val;
	while(t-- > 0)
    {
	cin>>c>>d;
   val=(c*d)-c-d;
    cout<<val<<endl;
	}

return 0;
}
