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
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int t,i,N;
        S(t);
        LL sum,avg,ans,to_sub, cur_avg,last_avg;
        LL a[10005];
        while(t--)
        {
            S(N);
            sum=0;
            for(i=1;i<=N;i++)
            {
               SL(a[i]);
            }
            sum=a[1];
            cur_avg=0; last_avg=a[1];
            for(i=2;i<N;i++)
            {
                sum+=a[i];
               // cout<<"l "<<last_avg<<"  ";
                cur_avg=( last_avg*(i-1)+ a[i])/i;
                 cout<<"l "<<last_avg<<"  "<<cur_avg<<" ";
                if(cur_avg >= last_avg)
                {
                    cur_avg= last_avg;
                }

                if((sum-cur_avg*i)>0)
                {
                    a[i+1]+= (sum-cur_avg*i);
                    a[i]=cur_avg;
                }
                cout<<cur_avg<<endl;
            }
            if(a[N]<cur_avg)
                ans=a[N];
            for(i=1;i<=N;i++)
                cout<<a[i]<<"  ";
            cout<<endl;
            printf("%lld\n",cur_avg);
        }
return 0;
}
