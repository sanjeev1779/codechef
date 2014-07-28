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
main()
{
    int n,i;
    cin>>n;
    LL a[n+5];
    if(n==1)
    {
        cin>>a[1];
        cout<<"1\n";
        return 0;
    }
    cin>>a[1]>>a[2];
    int maxm=-1;
    int r=2;
    for(i=3;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1]+a[i-2])
            {
                r++;
            }
            else
            {
                maxm= max(maxm,r);
                r=2;
            }
    }
    maxm= max(maxm,r);
    cout<<maxm<<endl;
return 0;
}
