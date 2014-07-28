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
    double y,ans;
    int x;
    cin>>x>>y;
    if(x%5!=0)
        printf("%.2lf\n",y);
    else if(y>=x*1.0+0.5)
    {
        ans= (y-x*1.0-0.5);
        printf("%.2lf\n",ans);
    }
    else
        printf("%.2lf\n",y);

return 0;
}
