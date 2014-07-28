#include<cstring>
#include<stdio.h>
#include<iostream>
using namespace std;
int i,j;
void dp(int P[],int C[],int P_min, int N)
{
    int Kp[N+1][5002];
    memset(Kp,0,sizeof(Kp));
    // K[i][j] using i items and j costs maxm pleasure is K[i][j]
    for(i=0;i<N;i++)
    {
        if(i==0)
            Kp[0][C[0]]=P[0];
        else
        {
            for(j=0;j<5002;j++)
            {
                if(j<C[i])
                {
                    Kp[i][j]=Kp[i-1][j];
                }
                else
                {
                    Kp[i][j]= max( Kp[i-1][j], P[i]+Kp[i-1][j-C[i]]);
                }
            }
        }
    }
    for(j=0;j<5002;j++)
    {
        if(Kp[N-1][j]>=P_min)
        {
            printf("%d %d\n",j,Kp[N-1][j]);
            return ;
        }
    }
}
main()
{
    int t,N,P_min,C;
    string str;
    scanf("%d",&t);
    while(t--)
    {
        cin>>N>>P_min;
        int P[N+1],C[N+1];

        for(i=0;i<N;i++)
        {
            cin>>str;
            cin>>P[i]>>C[i];
        }

        // dp
        dp(P,C,P_min,N);
    }
}
