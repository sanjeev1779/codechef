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
    int t,cnt,i,j,x1,y1,flag,N,ans;
    S(t);
    char c;
    for(int ll=1;ll<=t;ll++)
    {
        ans=0;
        S(N);
        int a[N+2][N+2];
        string str;
        for(i=1;i<=N;i++)
        {
            cin>>str;
            for(j=1;j<=N;j++)
            {
                if(str[j-1]=='.')
                    a[i][j]=0;
                else a[i][j]=1;
            }
        }
        flag=0;
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(a[i][j]==1)
                    {
                            cnt=1;
                            flag=1;
                             x1=i,y1=j;
                   // cout<<"first cnt= "<<cnt<<endl;
                    for(;j<N;j++)
                    {
                        if(a[i][j]==1 && a[i][j+1]==1)
                            cnt++;
                        else {break;}
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        int first_time=0,flag_false=0;
        int length=0;
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(a[i][j]==1 && first_time==0)
                {
                    first_time=1;
                    if(i+cnt-1>N || j+cnt-1>N)
                    {
                        flag_false=1;
                        ans=1;
                        break;
                    }
                }
                if(i>=x1 && i<=x1+cnt-1 && (x1+cnt-1)<=N && j>=y1 && j<=y1+cnt-1 && (y1+cnt-1)<=N)
                {
                    if(a[i][j]==0)
                    {
                        ans=1;
                        break;
                    }
                }
                else
                    if(a[i][j]==1)
                    {
                        ans=1;
                        break;
                    }
                }

            if(ans==1 || flag_false==1)
                break;
        }
       // cout<<x1<<" "<<y1<<endl;
        //cout<<"cnt = "<<cnt<<endl;
        //cout<<"ans = "<<ans<<endl;
        if(ans==0)
            printf("Case #%d: YES\n",ll);
        else
            printf("Case #%d: NO\n",ll);
    }
return 0;
}
