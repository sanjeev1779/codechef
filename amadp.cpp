// www.facebook.com/sanjeev1779
// www.codechef.com/users/sanjeev1779

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
    int n;
    cin>>n;
    int a[n],i;
    int dp[n];
	for( i=0;i<n;i++)
        cin>>a[i];
    dp[0]=a[0];
    dp[1]=a[1];
    for(i=2;i<n;i++)
    {
        if(dp[i-1]>a[i]+dp[i-2])
            dp[i]=dp[i-1];
        else
            dp[i]=a[i]+dp[i-2];
    }
    for( i=0;i<n;i++)
        cout<<dp[i];

return 0;
}
