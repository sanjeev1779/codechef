#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    #ifdef _MSC_VER
	freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
#endif
    //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int t;S(t);
    int x1,x2,y1,y2,a1,a2,b1,b2,i,j,cnt;
    while(t--)
    {
        cnt=0;
       scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
       scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
        for(i=0;i<=1000;i++)
        {
            for(j=0;j<=1000;j++)
            {
                if(i>=x1&& i+1<=x2 && j>=y1 && j+1<=y2 || i>=a1&& i+1<=a2 && j>=b1 && j+1<=b2)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
return 0;
}
