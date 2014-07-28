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
    int test_cases,N,x,y,maxm_x,maxm_y,minm_x,minm_y;
    S(test_cases);
    LL ans;
    while(test_cases--)
    {
        S(N);
        maxm_x= maxm_y=-100005;
        minm_y= minm_x= 100005;
        while(N--)
        {
            S(x);S(y);
            if(x>=maxm_x)
                maxm_x=x;
            if(y>=maxm_y)
                maxm_y=y;
            if(x<=minm_x)
                minm_x=x;
            if(y<=minm_y)
                minm_y=y;
        }
       ans= abs((maxm_x-minm_x)* (maxm_y- minm_y));
       printf("%lld\n",ans);
    }

return 0;
}
