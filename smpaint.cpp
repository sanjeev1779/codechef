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
int ans[1000100][5];
int ans2[1000100][5];
int a[1002][1002];
main()
{
    int start,color,x;
    int maxm_col,maxm;
    memset(ans,0,sizeof(ans));
     memset(a,0,sizeof(a));
    int N,i,j,k,idx,cnt,flag;
    S(N);
    int maxm_freq[N+3];
    int freq[102]={0};
    for(i=1;i<=N;i++)
    {
        memset(freq,0,sizeof(freq));
        for(j=1;j<=N;j++)
            {
                S(a[i][j]);
                freq[a[i][j]]++;
            }
        maxm=-1;
        for(k=0;k<=100;k++)
        {
            if(freq[k]>=maxm)
            {
                maxm=freq[k];
            }
        }
        maxm_freq[i]= maxm;
    }

    idx=0;
    for(i=1;i<=N;i++)
    {
        start=i;
        maxm_col= maxm_freq[i];
         ans[idx][0]= maxm_col; ans[idx][1]= start; ans[idx][2]= start; ans[idx][3]=1; ans[idx][4]=N; idx++;

        for(j=1;j<=N;)
        {
            color= a[i][j];
            x=0;
            if(color!= maxm_col)
            {

                for(k=j+1;k<=N;k++)
                {
                    if(a[i][k]== color)
                        x++;
                    else break;
                }
                ans[idx][0]= color; ans[idx][1]= start; ans[idx][2]= start; ans[idx][3]= j; ans[idx][4]=j+x; idx++;
                j=j+x;
            }
            j++;
        }// j ends here
    }// i here ends

    //-------------------------------------------------------------------------------------
    // 2nd method
    maxm=-1;
    int idx2=0;
    int max_color;
    for(i=0;i<=100;i++)
    {
        if(freq[i]>=maxm)
        {
            max_color=i;
            maxm= freq[i];
        }
    }
    if(max_color!=0)
    {
        ans2[idx2][0]= max_color; ans2[idx2][1]=1; ans2[idx2][2]=N; ans2[idx2][3]=1; ans2[idx2][4]=N;
        idx2++;
    }

    for(i=1;i<=N;i++)
    {
        start=i;
        for(j=1;j<=N;)
        {
            color= a[i][j];
            x=0;
            if(a[i][j]!= max_color)
            {

                for(k=j+1;k<=N;k++)
                {
                    if(a[i][k]== color)
                        x++;
                    else break;
                }
                ans2[idx2][0]= color; ans2[idx2][1]= start; ans2[idx2][2]= start; ans2[idx2][3]= j; ans2[idx2][4]=j+x; idx2++;
                j=j+x;
            }
            j++;
        }// j ends here
    }// i here ends
    // 2nd method ends here
    if(idx2<idx)
    {
        cout<<idx2<<endl;
        for(i=0;i<idx2;i++)
        {
            printf("%d %d %d %d %d\n",ans2[i][0],ans2[i][1],ans2[i][2],ans2[i][3],ans2[i][4]);
        }
    }
    else
    {
        cout<<idx<<endl;
        for(i=0;i<idx;i++)
        {
            printf("%d %d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3],ans[i][4]);
        }
    }
return 0;
}
