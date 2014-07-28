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
    int test_cases,C2,C3,white,black,i,j,N,M;
    string str;
    S(test_cases);
    int grid[105][105];
    while(test_cases--)
    {
        S(N);
        S(M);
        S(C2);
        S(C3);
        white=0;
        black=0;
        memset(grid,0,sizeof(grid));
        for(i=1;i<=N;i++)
        {
            cin>>str;
            for(j=1;j<=M;j++)
            {
                if(str[j-1]=='B')
                    {
                        grid[i][j] = 1; //BLACK
                        black++;
                    }
                else
                   {
                        grid[i][j]=0;
                        white++;
                   }
            }
        }

        printf("%d\n",black);
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                if(grid[i][j]==1) //WHITE
                    printf("%d %d %d\n",3,i,j);
            }
        }
    }

return 0;
}
