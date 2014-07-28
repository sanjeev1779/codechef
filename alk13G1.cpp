#include<iostream>
#include<stdio.h>
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
using namespace std;
int main()
{
    int test,N,i;
    cin>>test;long long arr[100006];
    long long ans;
    long long sum, cur_sum, maxm=0,total_arr_sum;
    for(int j=1;j<=test;j++)
    {
        S(N);
        cur_sum=0; sum=0;  maxm=0,total_arr_sum=0;


        for(int k=1;k<=N-1;k++)
        {
            cin>>arr[k]; total_arr_sum+=arr[k];
            if(arr[k]<=0)
                cur_sum+=(-arr[k]);
            else if(arr[k]>0 && arr[k-1]<=0 && k>=1)
            {
                maxm= max(cur_sum,maxm);
                cur_sum=0;
            }
        }
        cin>>arr[N];
          total_arr_sum+=arr[N];
        if(arr[N]<=0)
            cur_sum+=(-arr[N]);
        maxm= max(cur_sum,maxm);
        //cout<<maxm<<endl;
        ans= total_arr_sum+2*maxm;
        cout<<ans<<endl;
    }
return 0;
}
