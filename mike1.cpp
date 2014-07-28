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
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int N,M,i,j,x,y;
    LL L;
    cin>>N>>M;
    LL a[N+2][M+2];
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    cin>>L;
    int flag1=0, flag2=0;
    LL e1=0, e2=0;
    while(L--)
    {
        scanf("%d %d",&x,&y);
        if(x<=N && y<=M && flag1==0)
        {
            e1+= a[x][y];
        }
        else
        {
            flag1=1;
            e1=-1;
        }

        if(x<=M && y<=N && flag2==0)
        {
            e2+= a[y][x];
        }
        else
        {
            flag2=1;
             e2 =-1;
        }
    }
   LL ans= max(e1,e2);
    printf("%lld\n",ans);

return 0;
}
