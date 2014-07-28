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
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
          //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int t,i,N,K,r1,r2,j;
      S(t);
      int cost[505];
      char str[55];
      int times[10005];
      while(t--)
      {
          memset(times,0,sizeof(times));
          S(N); S(K);
          for(i=0;i<N;i++)
          {
             getchar();
             gets(str);
             S(cost[i]);
             times[cost[i]]++;
          }
          int ans=0;
          for(i=0;i<N;i++)
          {
              r1= K-cost[i];
              if(r1<0)continue;

              for(j=i+1;j<N;j++)
              {
                  r2=r1-cost[j];
                  if(r2<0) continue;
                  int x= times[r2];
                  if(cost[i]==r2)x--;
                  if(cost[j]==r2) x--;
                  if(x>0)
                    ans+=x;
              }
          }
          P(ans/3);
      }

return 0;
}
