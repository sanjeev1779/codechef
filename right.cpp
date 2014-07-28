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
long long   n,a1,a2,i,a3;
long long  a[3][2];
 cin>>n;
 long long ans=0;
 while(n--){

 for(i=0;i<3;i++)
 {
     scanf("%lld",&a[i][0]);
     scanf("%lld",&a[i][1]);
 }


  a1= (a[0][0]-a[1][0])*(a[0][0]-a[1][0])+ (a[0][1]-a[1][1])*(a[0][1]-a[1][1]);
  a2 = (a[1][0]-a[2][0])*(a[1][0]-a[2][0])+ (a[1][1]-a[2][1])*(a[1][1]-a[2][1]);
  a3 = (a[2][0]-a[0][0])*(a[2][0]-a[0][0])+ (a[2][1]-a[0][1])*(a[2][1]-a[0][1]);
  if(a1+a2==a3 || a1+a3==a2 || a2+a3==a1)
   cout<<"YES\n";
  else
    cout<<"NO\n";
 }


return 0;
}
