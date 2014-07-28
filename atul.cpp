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
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int t;
        S(t);
        LL x,y;
        int ans=0;
        while(t--)
        {
            SL(x); SL(y);
            ans=(x%3)%2+ (y%2)%2;
            cout<<ans<<endl;
        }
return 0;
}
