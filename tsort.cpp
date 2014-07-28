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
#define pb push_back
using namespace std;
int count1[1000001];
main()
{
    int n,x,j,i;
    int t;
   // int minm=1000005;
    //int maxm=-1;
    //memset(count1,0,sizeof(count1));
    S(n);
    for(i=0;i<n;i++)
    {
        S(count1[i]);
        //count1[x]++;
      //  minm=min(minm,x);
        //maxm=max(maxm,x);
    }
    sort(count1,count1+n);
    for(i=0;i<n;i++)
    {

            P(count1[i]);

    }

return 0;
}
