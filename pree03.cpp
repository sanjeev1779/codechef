#include<stdio.h>
#include<iostream>
#define LL long long
using namespace std;

LL kadane(int a[], int n)
{

    LL maxm=0;
    LL final_max=a[0];
    for(int i=0;i<n;i++)
    {
        if(maxm+a[i]>=0)
        {
            if(maxm<0)
                maxm=a[i];
            else
                maxm+=a[i];
        }
        else
            maxm=a[i];
        final_max= max(maxm, final_max);
    }
    return final_max;

}
 main()
{
   int test,i,n;
   cin>>test;
   int a[7005];
   while(test--)
   {
       scanf("%d",&n);
       for(i=0;i<n;i++)
            scanf("%d",&a[i]);

           printf("%lld\n", kadane(a, n));
   }
return 0;
}
