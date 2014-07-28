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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int n,i;
    int a[5][5];
    S(n);
    for(i=0;i<4;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];

    }
    int f=0;
    for(i=0;i<4;i++)
    {
         if(a[i][0]+a[i][2]==n)
        {
            printf("%d %d %d\n",i+1,a[i][0],n-a[i][0]);
            f=1;
            break;
        }
        else if(a[i][0]+a[i][3]<=n)
        {
            printf("%d %d %d\n",i+1,a[i][0],n-a[i][0]);
            f=1;
            break;
        }
        else
            if(a[i][1]+a[i][2]<=n)
        {
            printf("%d %d %d\n",i+1,a[i][1],n-a[i][1]);
            f=1;
            break;
        }
        else if(a[i][1]+a[i][3]<=n)
        {
            printf("%d %d %d\n",i+1,a[i][1],n-a[i][1]);
            f=1;
            break;
        }
    }
    if(f==0)
        printf("-1\n");
return 0;
}
