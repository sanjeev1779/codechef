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
      int n;
      cin>>n;
      LL a[n+5];
      for(i=1;i<=n;i++)
        SL(a[i]);
    a[0]=0;
    maxm=1;
      for(i=1;i<=N;i++)
      {
            if(a[i]<=maxm)
            {
                a[i]=maxm+1;
                maxm++;
            }
      }

return 0;
}
