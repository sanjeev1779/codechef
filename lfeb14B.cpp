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
LL mod= 1000000007;
LL po(LL a, LL b)
{
    LL prod=1;
    while(b>0)
    {
        if(b&1) prod=(prod*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return prod%mod;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int t,i,n;
    S(t);
    while(t--)
    {
        S(n);
        int a[n+2];
        int maxm=-1;
        for(i=0;i<n;i++)
        {
            S(a[i]);
            maxm= max(a[i],maxm);
        }
        int cnt=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==maxm)
              cnt++;
        }
        LL ans= po(2,cnt)-1;
        cout<<ans<<endl;
    }
return 0;
}
