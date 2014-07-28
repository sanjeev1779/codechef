#include<iostream>
#include<math.h>
using namespace std;
#define max(a,b) if(a>b)?a:b;
int number_of_ones(int num)
{
    int c=0,rem;
    while(num>0)
    {
        rem=num%2;
        if(rem==1)
          c++;
        num=num/2;
    }
    return c;
}

main()
{
   int test_Cases,n,a0,a1,b0,b1,diff,b,a;
    int ans,i;
    cin>>test_Cases;
    while(test_Cases--)
    {
        ans=0;
        cin>>n>>a>>b;

         a1=number_of_ones(a);
         a0=n-a1;

         b1=number_of_ones(b);
         b0=n-b1;
         diff=  min(a1,b0)+ min(a0,b1);
         for(i=n-1;i>=n-diff;i--)
         {
             ans=ans+ pow(2,i);
         }
         cout<<ans<<endl;

    }

return 0;
}
