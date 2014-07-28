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
    int T;
    S(T);
    double ans,R;
    while(T--)
    {
        scanf("%lf",&R);
        ans= R*sqrt(2.0);
        printf("%.8lf\n",ans);
    }

return 0;
}
