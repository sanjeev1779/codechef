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
main()
{
    int test_cases,N;
    LL D,B;
    S(test_cases);
    double sqrt_D;
    LL ans;
    while(test_cases--)
    {
        S(N);
        scanf("%lld",&B);
        D= (1+8*B);
        sqrt_D= (sqrt(D*1.0) -1.0)/2.0;
        ans= N*(N+1)/2;
        if(sqrt_D== (int) sqrt_D && B!=0)
            ans--;
        printf("%lld\n",ans);

    }


return 0;
}
