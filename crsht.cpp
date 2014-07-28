#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#include<queue>
#include<limits.h>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int test_cases,i,j,k,a,b,Q,t,N,top, min_idx,k1,minm;
int visited[205];
int adj[205][205];
int D[202];
int dijistra(int a, int b,int N)
{
    memset(visited,0,sizeof(visited));
    memset(D,0,sizeof(D));


            i=a;
            t=b;
                for(j=0;j<N;j++)
                  {
                      D[j] = INT_MAX;
                  }


                D[a]=0;
                for(k=0;k<N-1;k++)
                {

                    minm= INT_MAX;
                    for(k1=0;k1<N;k1++)
                    {
                        if(visited[k1]==0 && D[k1]<=minm)
                            {
                                minm= D[k1];
                                min_idx=k1;
                            }
                    }

                    //minm index vertex
                    visited[min_idx]=1;
                    for(j=0;j<N;j++)
                    {

                            if( !visited[j] && D[min_idx]!=INT_MAX && D[j]>D[min_idx]+1 && adj[min_idx][j]==1)
                            {
                                D[j]= D[min_idx]+1;
                            }

                    }
                }
             return D[b];

}
main()
{

    string str;
    S(test_cases);

    while(test_cases--)
    {
        S(N);

        for(i=0;i<N;i++)
        {
            cin>>str;
            for(j=0;j<N;j++)
            {
                if(str[j]=='N')
                    {
                        adj[i][j]=0;
                        adj[j][i]=0;
                    }
                else
                    {
                        adj[i][j]=1;
                        adj[j][i]=1;
                    }
            }
        }
        cin>>Q;
        while(Q--)
        {
            scanf("%d %d",&a,&b);
                printf("%d\n",dijistra(a,b,N));
        }
    }

return 0;
}
