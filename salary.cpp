#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
main()
{

   int test_cases,n,i;
   cin>>test_cases;
   while(test_cases--)
   {
        cin>>n;
        int a[102];
        cin>>a[0];
        int ans=0;
        int minm=a[0];
        for(i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            minm=min(minm,a[i]);
        }
        for(i=0;i<n;i++)
        {
            ans=ans+(a[i]-minm);
        }
        cout<<ans<<endl;

   }
return 0;
}
