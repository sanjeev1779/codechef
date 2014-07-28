// codeforces
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int t,i,N,x,temp,cur;
    S(t);
    long int start;
    while(t--)
    {
        S(N);
        S(x);
        start=x;
        cur=x;
        cur--;
        for(i=2;i<=N;i++)
        {
            S(x);
            if(cur<x)
            {
               // printf("%d\n",i);
                start=start+(x-cur);
                cur= x;
            }
            cur--;
        }
        printf("%ld\n",start);

    }

return 0;
}
