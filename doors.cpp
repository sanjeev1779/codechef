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
using namespace std;
main()
{
    int test_Cases;
    S(test_Cases);
    int num,a;
    int ans;
    while(test_Cases--)
    {
        S(num);
        a=1;
        while(a<=num)
        {
            a*=2;
        }
        a/=2;
        ans= 2*(num-a)+1;
        printf("%d\n",ans);
    }

return 0;
}
