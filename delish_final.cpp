#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string.h>
#define LL long long
#define max_size 10002
using namespace std;

LL max_front[max_size], min_front[max_size], max_end[max_size], min_end[max_size];

void maxm_from_front(LL a[], LL n)
{
    memset(max_front,0,sizeof(max_front));
    LL i=0,curr_sum=0,maxm=a[0];

    for(i=0;i<n;i++)
    {
        if( curr_sum+ a[i] >= 0)
        {
            if(curr_sum<0)
                curr_sum= a[i];
            else
                curr_sum+= a[i];
        }
        else
            curr_sum=a[i];
        max_front[i] = maxm= max( maxm, curr_sum);
    }
}

void maxm_from_end(LL a[],LL n)
{
    memset(max_end,0,sizeof(max_end));
    LL i,curr_sum=0,maxm= a[n-1];
    for(i=n-1;i>=0;i--)
    {
        if(curr_sum + a[i] >=0)
        {
            if(curr_sum<0)
                curr_sum=a[i];
            else
                curr_sum+= a[i];
        }
        else
            curr_sum= a[i];

        max_end[i]= maxm=max(maxm, curr_sum);
    }
}

void minm_from_front(LL a[], LL n)
{
    memset(min_front,0,sizeof(min_front));

    LL i,curr_sum=0,minm=a[0];
    for(i=0;i<n;i++)
    {
        if(curr_sum+a[i]<=0)
        {
            if(curr_sum>0)
                curr_sum=a[i];
            else
                curr_sum+= a[i];
        }
        else
            curr_sum=a[i];
        min_front[i]= minm= min(minm, curr_sum);
    }
}

void minm_from_end(LL a[], LL n)
{
     memset(min_end,0,sizeof(min_end));
    LL i,curr_sum=0,minm=a[n-1];
    for(i=n-1;i>=0;i--)
    {
        if(curr_sum+a[i]<=0)
        {
            if(curr_sum>0)
                curr_sum=a[i];
            else
                curr_sum+=a[i];
        }
        else
            curr_sum=a[i];

        min_end[i]= minm= min( minm, curr_sum);
    }

}
LL absolute(LL n)
{
    if(n>0) return n;
    else return -n;
}

main()
{
    LL test_cases,n,i,ans1,ans2,maxm;
    scanf("%lld",&test_cases);
    while(test_cases--)
    {
        scanf("%lld",&n);
        LL a[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }

        maxm_from_front(a,n);
        maxm_from_end(a,n);
        minm_from_front(a,n);
        minm_from_end(a,n);

          /* cout<<"\nmax from front\n";
          for(i=0;i<n;i++)
                cout<<max_front[i]<<"\t";

           cout<<"\nmin from end\n";
           for(i=0;i<n;i++)
                cout<<min_end[i]<<"\t";
           cout<<"\n min from front\n";
           for(i=0;i<n;i++)
                cout<<min_front[i]<<"\t";

           cout<<"\n max from end\n";
           for(i=0;i<n;i++)
                cout<<max_end[i]<<"\t";
            cout<<"end\n";*/
        //iterate over n from 1 to n-1 th index
        ans1=0;
        for(i=0;i<n-1;i++)
        {
            maxm= absolute( max_front[i]- min_end[i+1]);
            ans1= max(ans1, maxm);
        }


        //similarly for maximizing end and minimizing front
        ans2=0;
        for(i=0;i<n-1;i++)
        {
            maxm= absolute( min_front[i]- max_end[i+1] );
            ans2= max(ans2, maxm);
        }

        ans1= max(ans1,ans2);
        printf("%lld\n",ans1);
    }
return 0;
}
