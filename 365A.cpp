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
    int n,k,i;
    LL num;
    int rem;
    cin>>n>>k;
    int ans=n;
     int a[10]={0};
    for(int j=0;j<n;j++)
    {
        cin>>num;

        memset(a,0,sizeof(a));
        while(num>0)
        {
            rem=num%10;
            num/=10;
            a[rem]++;
        }
        for(i=0;i<=k;i++)
        {
            if(a[i]==0)
            {
                ans--;
                break;
            }
        }
    }
    cout<<ans<<endl;
return 0;
}
