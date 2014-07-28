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
    int test_cases,N,K,i,j,row_idx,flag;
    LL sum;
    S(test_cases);
    vector<int>vec;
    pair<double,int>p[100002];
    while(test_cases--)
    {

        S(N);S(K);
        LL a[N+1][K+1];
        LL col_sum[K+1];
        memset(col_sum,0,sizeof(col_sum));
        double avg[N+1];LL last_arr[K+1];
        for(i=0;i<N;i++)
        {
            sum=0;
            for(j=0;j<K;j++)
            {
                SL(a[i][j]);
                sum+=a[i][j];
            }
            avg[i]=(double)(sum)/(K*1.0);
            p[i]= mp(avg[i],i);
        }
        for(j=0;j<K;j++)
            SL(last_arr[j]);
        sort(p,p+N);
        for(i=0;i<N;i++)
        {
            flag=0;
            row_idx= p[i].second;
            //cout<<"row index= "<<row_idx<<endl;
            for(j=0;j<K;j++)
            {
                col_sum[j]+= a[row_idx][j];
              //  cout<<"j= "<<j<<" : "<<col_sum[j]<<" and last arr"<<last_arr[j]<<endl;
                if(col_sum[j]>last_arr[j])
                    {
                       // cout<<"hi\n";
                        flag=1;
                        break;
                    }
            }
            if(flag)
                break;
            vec.pb(row_idx+1);
        }
        int l = vec.size();
        P(l);
        for(i=0;i<l;i++)
            printf("%d ",vec[i]);
        printf("\n");
        vec.clear();
    }

return 0;
}
