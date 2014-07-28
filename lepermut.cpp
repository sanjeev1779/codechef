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

    int T;
    cin>>T;
    int i,j,n;
    int loc,inv;
    int a[102];
    while(T--)
    {
        S(n);
        memset(a,0,sizeof(a));
        S(a[0]);
        loc=0;
        inv=0;
        for(i=1;i<n;i++)
        {
            S(a[i]);
            if(a[i]<a[i-1])
                loc++;
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                    inv++;
            }
        }
        if(loc==inv)
            printf("YES\n");
        else
            printf("NO\n");
    }

return 0;
}
