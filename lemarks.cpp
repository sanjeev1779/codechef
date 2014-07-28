#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#include<climits>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int t,ans,N,i,j;
    S(t);
    double avg;
    while(t--)
    {
        S(N);
        int a[N+1][N+1];
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
                S(a[i][j]);
        }

        //dp
        ans=-1;
        int dp_max[N+2][N+2];
        int dp_min[N+2][N+2];
        memset(dp_max,0,sizeof(dp_max));
        memset(dp_min,0,sizeof(dp_min));
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                dp_max[i][j]= max(dp_max[i-1][j]+a[i][j],dp_max[i][j-1]+a[i][j]);
                if(i==1)
                {
                    dp_min[1][j]= dp_min[1][j-1]+a[1][j];
                }
                else if(j==1)
                {
                    dp_min[i][j]=dp_min[i-1][1]+a[i][j];
                }
                else
                {
                    dp_min[i][j]= min(dp_min[i-1][j]+a[i][j],dp_min[i][j-1]+a[i][j]);
                }
            }
        }
        /*printf("maxm sum= %d\n",dp_max[N][N]);
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
                printf("%d ",dp_max[i][j]);
            printf("\n");
        }*/
        avg= (dp_min[N][N]*1.0)/(2.0*N-1.0);
        printf("%.6lf\n",avg);
        avg= (dp_max[N][N]*1.0)/(2.0*N-1.0);
        printf("%.6lf\n",avg);
       /* for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
                printf("%d ",dp_min[i][j]);
            printf("\n");
        }
        printf("minm sum= %d\n",dp_min[N][N]);*/

    }

return 0;
}
