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

    int N,sum=0,a[10],i,x;
    memset(a,0,sizeof(a));

    int flag=0;
    S(N);
    vector<int>v;
    for(i=0;i<N;i++)
    {
        S(x);
        a[x]++;
    }
    int j;
    int rem= a[5]/9;
    if(rem>0 && a[0]>0)
    {
        for(i=0;i<rem;i++)
        {
            for(j=0;j<9;j++)
                printf("5");
        }
        for(i=0;i<a[0];i++)
             printf("0");
    }
    else if(a[0]>0)
         printf("0\n");
    else
         printf("-1\n");





return 0;
}
