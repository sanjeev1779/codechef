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
main()
{
    int n,i,maxm=0,j;
    S(n);
    int a[n+1];
    int max_length[n+2];
    for(i=0;i<n;i++)
        S(a[i]);
    for(i=0;i<n;i++)
        max_length[i]=1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if( a[i]>=a[j] && max_length[i]<max_length[j]+1)
                 max_length[i]=max_length[j]+1;
        }
        maxm= max(maxm,max_length[i]);
    }
   printf("%d\n",maxm);



return 0;
}
