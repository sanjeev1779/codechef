#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;
main()
{
    int test_cases,sum,i,ans1,ans2,n,k,right_sum,left_sum1,left_sum2,right_sum1,right_sum2,r_ans1,l_ans2;
    int w[100];
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>n>>k;
        sum=0;
        left_sum1=0;
        right_sum1=0;
        left_sum2=0;
        right_sum2=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            sum+=w[i];
        }
        sort(w,w+n);

        for(i=0;i<k;i++)
        {
            left_sum1+= w[i];
        }
        ans1 = abs(sum-2*left_sum1);
        for(i=n-1;i>=n-k;i--)
        {
            left_sum2+=w[i];
        }
        ans2= abs(sum-2*left_sum2);
      //  printf("l=%d r=%d\n",left_sum,right_sum);
       // printf("%d %d\n",ans1,ans2);
        ans1= max(ans1,ans2);
        cout<<ans1<<endl;

    }
return 0;
}
