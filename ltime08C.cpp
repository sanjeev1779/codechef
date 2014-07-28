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
      int t,N,i;
      S(t);
      LL wt,c,K,w;
      LL sum;
      while(t--)
      {
          S(N); SL(K);
          pair<LL,LL>p[N+2];
          for(i=0;i<N;i++)
          {
             cin>>c>>w;
             p[i]=mp(c,w);
          }
          sort(p,p+N);
          sum=0;
          wt=0;
          for(i=0;i<N;i++)
          {
              if(sum+p[i].first<=K)
              {
                  sum+=p[i].first;
                  wt+=p[i].second;
              }else break;
          }
          cout<<wt<<endl;
      }

return 0;
}
