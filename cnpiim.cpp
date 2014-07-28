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
bool isprime(int x)
{
    for(int i=2;i<x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
       int t;
       S(t);
       int x,y,sum;
       while(t--)
       {
           S(x) S(y);
           sum=x+y+1;
           while(1)
           {
               if(isprime(sum)) { P(sum-x-y); break;}
               sum++;
           }
       }
return 0;
}
