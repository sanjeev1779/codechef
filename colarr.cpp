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
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int test_Cases;
    S(test_Cases);
    while(test_Cases--)
    {
        S(N);S(M);S(K);
        for(i=1;i<=N;i++)
        {
            S(col[i]);
        }
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                S(B[i][j]);
            }
        }
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                S(C[i][j]);
            }
        }

        for(i=1;i<=N;i++)
        {
            old= B[i][col[i]];
            maxm= -1;
            for(j=1;j<=M;j++)
            {
                new_val= B[i][j]-C[i][j];
                diff= new_val-old;
                if(diff>=0)
                {
                    maxm= max(maxm,diff);
                }
            }
        }
    }
return 0;
}
