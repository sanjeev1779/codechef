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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int t;
    S(t);
    char c;
    while(t--)
    {
        S(N);
        int a[N+2][N+2];
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                cin>>c;
                if(c=='.')
                    a[i][j]=0;
                else a[i][j]=1;
            }
        }

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(a[i][j]==1)
                {
                    x1=i,y1=j;
                    for(k=x1+1;k<=N;k++)
                    {
                        if(a[i][k]==1)
                        {
                            for()
                        }
                    }
                }
            }
        }
    }
return 0;
}
