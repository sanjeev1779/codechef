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
    int t;
    S(t);
    int N,k,i;
    LL S;
    while(t--)
    {
        cin>>N>>k>>S;
        int a[N+5];
        pair<int,int>p[N+5];
        for(i=1;i<=N;i++)
        {
            cin>>a[i];
            p[i]= mp(a[i],i);
        }
        sort(p+1,p+N+1);
        for(i=1;i<=N;i++)
        {
            P(p[i].second);
            //if(sum>S) break;
        }
    }
return 0;
}
