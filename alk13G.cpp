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
    int t,N,i;
    S(t);int a[100002];
    LL cur_sum,tot_sum,minm;
    while(t--)
    {
        S(N);
        int flag=0;
        cur_sum=0;tot_sum=0;
        for(i=0;i<N;i++)
        {
            S(a[i]);tot_sum+=a[i];
            if(a[i]<0)
                flag=1;
        }
       // cout<<sum<<endl;
        minm=a[0];
        for(i=0;i<N;i++)
        {
            if(cur_sum+a[i]<=0)
            {
                if(cur_sum<=0)
                    cur_sum+=a[i];
                else
                    cur_sum=a[i];
            }
            else
                cur_sum=a[i];
            minm= min(minm,cur_sum);
        }
        //cout<<minm<<endl;
        if(flag)
        printf("%lld\n",(tot_sum-2*minm));
        else
            printf("%lld\n",(tot_sum));
    }

return 0;
}
