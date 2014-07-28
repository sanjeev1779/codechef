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
int test_cases,i,j,k,a,b,Q,N,top, min_idx,k1,minm;
int visited[20];
int adj[20][20];
int D[20];
int stop[20];
int a,b;
int dijistra(int a, int b)
{
    int N=15;
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

                            if( !visited[j] && D[min_idx]!=INT_MAX && D[j]>D[min_idx]+adj[a][b] && adj[min_idx][j]==1)
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
    char s,t;
    while(test_cases--)
    {
        for(i=0;i<N;i++)
        {
            S(stop[i]);
        }
        for(i=0;i<26;i++)
        {
            scanf("%c %c %d",&st,&en, &time);
            adj[st-'A'][en-'A']= time;
        }
        cin>>s>>t;
            printf("%d\n",ans);


    }

return 0;
}
