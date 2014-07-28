#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
       //   freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      LL a[1000],b[1000],k;int n,t;
      cin>>t;
      while(t--){
      cin>>n;
      LL temp;
      for(int i=0;i<n;i++)
      {
          cin>>temp;
          a[i]=k-temp;
      }
      for(int i=0;i<n;i++)
      {
          cin>>b[i];
      }
      sort(a,a+n);
      sort(b,b+n);
      int f=0;
      for(int i=0;i<n;i++)
      {
       if(b[i]>a[i]){
            cout<<"NO"<<endl;
            return 0;}
      }
      cout<<"YES"<<endl;
      }
return 0;
}
