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
        LL N,x1,x2,x3,y1,y2,y3,max_idx,min_idx,i,area;
        scanf("%lld",&N);
        LL minm= 10000000;
        LL maxm=-1;
        for(i=1;i<=N;i++)
        {
            scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3);
            area= x1*(y2-y3)+x2*(y3-y1)+ x3*(y1-y2);

            area= abs(area);
           // cout<<area<<endl;
            if(area>=maxm)
            {
                maxm= area;
                max_idx= i;
            }
            if(area<=minm)
            {
                minm=area;
                min_idx=i;
            }
        }

        printf("%lld %lld\n",min_idx, max_idx);

return 0;
}
