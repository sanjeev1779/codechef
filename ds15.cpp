#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
LL count_sum(int n)
{
    LL sum=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(i*i!=n)
                sum+=n/i;
        }
    }
    return sum-n;
}
main()
{
    int test_cases,n;
    LL ans;
    S(test_cases);
    while(test_cases--)
    {
        S(n);
        ans= count_sum(n);
        printf("%lld\n",ans);
    }
return 0;
}
