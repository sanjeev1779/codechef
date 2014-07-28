#include<climits>
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
LL max_back[100010];
LL max_front[100010];
LL arr[100010];

main()
{
    int test_cases,N,K,i;
    S(test_cases);
    LL maxm,temp,cur_sum;

    while(test_cases--)
    {
        S(N);S(K);
        for(i=1;i<=N;i++)
        {
            scanf("%ld",&arr[i]);
        }

        // find the maximum value from front

        maxm=arr[1];
        cur_sum=0;
        for(i=1;i<=N;i++)
        {
            if(cur_sum+arr[i]>=0)
            {
                if(cur_sum<0)
                    cur_sum=arr[i];
                else
                    cur_sum+=arr[i];
            }
            else
                cur_sum=arr[i];

            max_front[i]= maxm= max(maxm,cur_sum);
        }
        // find the maximum from back

        maxm=arr[N];
        cur_sum=0;
        for(i=N;i>=1;i--)
        {
            if(cur_sum+arr[i]>=0)
            {
                if(cur_sum<0)
                    cur_sum=arr[i];
                else
                    cur_sum+=arr[i];
            }
            else
                cur_sum=arr[i];
            max_back[i]= maxm= max(maxm,cur_sum);
        }
        // end of finding the maxm
        maxm= INT_MIN;
        for(i=1;i<=N-K-1;i++)
        {
            temp= max_front[i]+ max_back[i+K+1];
            if(temp>= maxm)
            {
                maxm=temp;
            }
        }
        printf("%ld\n",maxm);

    }

return 0;
}

