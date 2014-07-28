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
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int test_cases,C2,C3,white,black,i,j,N,M,k, row_black, row_white,white_black;
    string str;
    int W2B,B2W,flag,k1, c2_type;
    S(test_cases);
    int sum;
    int ans_t1[10005][6];
    int ans[10005][4];
    int grid[105][105];
    int black_white[102][3];
    while(test_cases--)
    {
        flag=0;
        sum=0;
        memset(black_white,0,sizeof(black_white));
        S(N); S(M); S(C2);S(C3);
        white=0;
        black=0;
        row_black=0;

        memset(grid,0,sizeof(grid));
        for(i=1;i<=N;i++)
        {
            cin>>str;
            row_black=0;
            row_white=0;
            for(j=1;j<=M;j++)
            {
                if(str[j-1]=='B')
                    {
                        row_black++;
                        grid[i][j] = 1; //BLACK
                        black++;
                    }
                else
                   {
                        grid[i][j]=0; // white
                        white++;
                        row_white++;
                   }
            }
            black_white[i][0]= row_black; // black
            black_white[i][1]= row_white; // white
        }
        W2B= white*C2;
        B2W= black*C3;

    // white to black cost is less than B2W , change W2B

              k=0;
            k1=0;
            for(i=1;i<=N;i++)
            {
                if(i%2==1)
                {
                    if(black_white[i][0]==0) // black is 0
                    {
                        ans[k][0]=2, ans[k][1]=i, ans[k][2]=M;
                        sum+=C2; // white to black
                        k++;
                        black_white[i][0]++; // black is added
                    }
                }
                else
                {
                    int x=0;
                    int j1;
                    for(j=1;j<=M;j++)
                    {
                        if(grid[i-1][j]==1 && grid[i][j]==0 && black_white[i-1][0]>1) // black to white
                        {
                            sum++;
                                    ans_t1[k1][0]= 1, ans_t1[k1][1]= i-1, ans_t1[k1][2]=j, ans_t1[k1][3]=i, ans_t1[k1][4]=j;
                                    grid[i-1][j]=0; // black to white
                                    grid[i][j]=1; // white to black
                                    k1++;
                                    black_white[i-1][0]--;black_white[i-1][1]++;
                                    black_white[i][0]++;black_white[i][1]--;
                        }
                        if(grid[i][j]==0) // W2B
                        {
                            sum+=C2;
                             grid[i][j]=1;
                             ans[k][0]=2, ans[k][1]=i, ans[k][2]=j;
                             k++;
                             black_white[i][0]++;
                             black_white[i][1]--;

                        }

                    }
                }
        }


        if(sum<=B2W)
        {
            printf("%d\n",k+k1);
            for(i=0;i<k1;i++)
            {
                printf("%d %d %d %d %d\n",ans_t1[i][0], ans_t1[i][1],ans_t1[i][2], ans_t1[i][3], ans_t1[i][4]);
            }
            for(i=0;i<k;i++)
            {
                printf("%d %d %d\n",ans[i][0], ans[i][1],ans[i][2]);
            }
        }
         else // black to white
        {
            printf("%d\n",black);
            for(i=1;i<=N;i++)
            {
                for(j=1;j<=M;j++)
                {
                    if(grid[i][j]==1)
                        printf("%d %d %d\n",3,i,j);
                }
            }
        }


    }

return 0;
}
