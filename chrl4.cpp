// codeforces
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
#define SL(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int N,i,j,x,y,k;
        S(N); S(k);
        int a[N+10];
        for(i=1;i<=N;i++)
            S(a[i]);
        int cost[N+2];
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=k&& j+i<=N;j++)
            {
                cost[i+j]= cost[i]*a[i+j];
            }
        }


return 0;
}
