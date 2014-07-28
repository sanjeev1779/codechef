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
int height[1005][1005];
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int N,M,K;
        S(N); S(M); S(K);
        int a[N+5][M+5];
        memset(a,0,sizeof(a));
        while(K--)
        {
            S(x) S(y)
            a[x][y]=1;
        }

        // height of each index
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                if(a[i][j]==1) // dangerous
                    height[i][j]=0;
                else
                    height[i][j]= height[i-1][j]+1;
            }
        }

return 0;
}
