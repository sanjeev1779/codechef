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
          freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);

     int test_cases,i,j,N,M,area,cur_area,x,y,k,ht,Q,L,R,K;

         S(N);S(M); S(K);
         int a[N+5][M+5];
         int l[N+2][N+2][M+2];
         int rt[N+2][N+2][M+2];
         int height[N+2][N+2][M+2];
         int ans[N+2][N+2];
         memset(height,0,sizeof(height));
         memset(l,0,sizeof(l));
         memset(rt,0,sizeof(rt));
         memset(ans,0,sizeof(ans));


         memset(a,1,sizeof(a));
         while(K--)
         {
             S(x) S(y)
             a[x][y]=0;
         }
         for(k=1;k<=N;k++)
         {
             for(i=k;i<=N;i++)
             {
                 for(j=1;j<=M;j++)
                 {
                     if(a[i][j]) // if free
                        height[k][i][j]= height[k][i-1][j]+1;
                    else height[k][i][j]=0;
                 }
             }
         }

        for(k=1;k<=N;k++)
        {
             for(i=k;i<=N;i++)
             {
                 for(j=1;j<=M;j++)
                 {
                    if(a[i][j]==0 || height[k][i][j-1]<height[k][i][j])
                        l[k][i][j]=0;
                    else l[k][i][j]= l[k][i][j-1]+1;
                 }
             }
        }

    for(k=1;k<=N;k++)
    {
         for(i=1;i<=N;i++)
         {
             for(j=M;j>=1;j--)
             {
                 if( a[i][j]=0 || height[k][i][j]> height[k][i][j+1])
                    rt[k][i][j]=0;
                 else rt[k][i][j]= rt[k][i][j+1]+1;
             }
         }
    }
         for(k=1;k<=N;k++)
         {
             area= -1;
             for(i=k;i<=N;i++)
             {
                 for(j=1;j<=M;j++)
                 {
                      ht= height[k][i][j];
                    cur_area= ht*( l[k][i][j]+ rt[k][i][j]+1); // l and r depends on h , so it is wrong here :(
                    area= max(area, cur_area);
                 }
                 cout<<k <<" to "<<i <<" =  height= "<<(i-k+1)<<" and area="<<area<<endl;
                 ans[k][i]=area;
             }
             cout<<endl;
         }
         S(Q);
         while(Q--)
         {
             S(L); S(R);
             printf("%d\n",ans[L][R]);
         }
return 0;
}
