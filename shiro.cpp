#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
#define vector<int>VI
using namespace std;

int N;
double a[101],x;
double sum_here[101];
int sum;
double prob[101];
double  mem[101][10001];
double shiro(int idx, int cur_sum)
{
    double taken, not_taken;
    if(cur_sum >= (sum+1)/2 )
        return 1.0;
    if( idx==N || ((sum-sum_here[idx-1]+ cur_sum)< (sum+1)/2 ) )
        return 0.0;
    if( mem[idx][cur_sum] > -1.0)
        return mem[idx][cur_sum];
     not_taken= (1-prob[idx])*shiro(idx+1, cur_sum);
     taken=  shiro(idx+1,cur_sum+a[idx]);


        double ans= prob[idx]*taken + not_taken;
    mem[idx][cur_sum]=ans;
    return ans;
}
main()
{
    int test_cases,i;
    cin>>test_cases;

    while(test_cases--)
    {
        memset(mem,-1,sizeof(mem));
        scanf("%d",&N);
        scanf("%lf",&a[0]);
        sum_here[0]=a[0];
        for(i=1;i<N;i++)
        {
            scanf("%lf",&a[i]);
            sum_here[i]=sum_here[i-1]+a[i];
        }
        sum= sum_here[N-1];
        for(i=0;i<N;i++)
        {
            scanf("%lf",&x);
            prob[i]=x/100.0;
        }

         double ans= shiro(0,0);
        printf("%.8lf\n",ans);

    }

return 0;
}
