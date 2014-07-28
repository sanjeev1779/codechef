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
using namespace std;
main()
{
    int test_cases,i;
    S(test_cases);
    LL D[10002];
    LL max_end[10002];
    LL min_end[10002];
    LL max_front[10002];
    LL min_front[10002];
    LL maxm1,maxm2,maxm,minm,cur_sum;
    int N;
    LL ans;
    while(test_cases--)
    {
        S(N);
        for(i=0;i<N;i++)
            scanf("%lld",&D[i]);


        // find the maximum front end
        maxm=D[0];
        cur_sum=0;
        for(i=0;i<N;i++)
        {
            if(cur_sum+D[i]>=0)
            {
                if(cur_sum<0)
                    cur_sum=D[i];
                else
                    cur_sum+=D[i];
            }
            else
                cur_sum=D[i];

            max_front[i]= maxm= max(maxm,cur_sum);
        }

        // finding the maximum from end
        cur_sum=0;
        maxm=D[N-1];
        for(i=N-1;i>=0;i--)
        {
            if(cur_sum+D[i]>=0)
            {
                if(cur_sum<0)
                    cur_sum=D[i];
                else
                    cur_sum+=D[i];
            }
            else
                cur_sum=D[i];
            max_end[i]=maxm= max(cur_sum,maxm);
        }

        //findin the minm front edge
        minm=D[0];
        cur_sum=0;
        for(i=0;i<N;i++)
        {
            if(cur_sum+D[i]<=0)
            {
                if(cur_sum>0)
                    cur_sum=D[i];
                else
                    cur_sum+=D[i];
            }
            else
                cur_sum=D[i];

            min_front[i]= minm= min(minm,cur_sum);
        }
        // finding the minm from back
        minm=D[N-1];
        cur_sum=0;
        for(i=N-1;i>=0;i--)
        {
            if(cur_sum+D[i]<=0)
            {
                if(cur_sum>0)
                    cur_sum=D[i];
                else
                    cur_sum+=D[i];
            }
            else
                cur_sum=D[i];

            min_end[i]= minm= min(minm,cur_sum);
        }

/*
          for(i=0;i<N;i++)
          {
              cout<<"max from front= "<<max_front[i]<<"\t";
          }
          cout<<endl;

          for(i=0;i<N;i++)
          {
              cout<<"minm from front= "<<min_front[i]<<"\t";
          }
          cout<<endl;


          for(i=N-1;i>=0;i--)
          {
              cout<<"minm from end= "<<min_end[i]<<"\t";
          }
          cout<<endl;

          for(i=N-1;i>=0;i--)
          {
              cout<<"maxm from end= "<<max_end[i]<<"\t";
          }
          cout<<endl;

          cout<<endl;*/
        maxm1=0;
        maxm2=0;
        for(i=0;i<N-1;i++)
        {
            maxm1= max(maxm1, abs( max_front[i]-min_end[i+1]) );
            maxm2= max(maxm2, abs(min_front[i]-max_end[i+1]));
        }
        ans= max(maxm1,maxm2);
        cout<<ans<<endl;

    }


return 0;
}

