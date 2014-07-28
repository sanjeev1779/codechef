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
#define max_size  100001
using namespace std;
LL a[max_size];

LL dp(LL n)
{
    if(n<max_size)
        return  a[n];
    int val= n/2 + n/3+ n/4; ;
    if(val>n)
        return dp(n/2)+ dp(n/3)+ dp(n/4);
    else
        return n;
}
main()
{
	LL i;
	LL n,next;

    for(i=0;i<max_size;i++)
    {
        next= a[i/2]+ a[i/3] +a[i/4];
        if( next>= i )
            a[i]=next;
        else
            a[i]=i;
    }


	while( (scanf("%lld",&n)>0) )
    {
        cout<<dp(n)<<endl;
    }

return 0;
}
