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
          //freopen("C:\\Users\\cyber\\Documents\\codechef\\prob1\\large_input.txt", "r", stdin);
       //freopen("C:\\Users\\cyber\\Documents\\codechef\\prob1\\large_output.txt", "w", stdout);
      int t,i,N;
      LL k;
      cin>>t;
      while(t--)
      {
         cin>>N;
         LL a[N+5];
         for(i=0;i<N;i++)
            cin>>a[i];
         sort(a,a+N);
         LL sum=0,temp;
         LL maxm_wt=-1;
         for(i=N-1;i>=0;i--)
        {
            k= N-i;
            temp= a[i]*k;
            if(temp>=maxm_wt)
                maxm_wt=temp;
         }
         printf("%lld\n",maxm_wt);
      }
return 0;
}
