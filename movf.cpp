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
        // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      vector <LL> a,b;
      LL k;int n,t;
      cin>>t;
      while(t--)
    {
      cin>>n>>k;
      LL temp;
      for(int i=0;i<n;i++)
      {
          cin>>temp;
          a.pb(k-temp);
      }
      for(int i=0;i<n;i++)
      {
          cin>>temp;
          b.pb(temp);
      }
      sort(a.begin(),a.end());
      sort(b.begin(),b.end());
      int f=0;
      for(int i=0;i<n;i++)
      {
       if(b[i]<a[i]){
            f=1;
            break;
            }
      }
      if(f==0)
      cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
      }
return 0;
}
