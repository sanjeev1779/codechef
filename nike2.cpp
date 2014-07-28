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
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);

        LL n,k,i,x;
        cin>>n>>k;
        LL a[n+3];
        LL sum=0;
        for(i=1;i<=n;i++)
        {
                SL(a[i]);
        }
        sort(a+1,a+n+1);
        int ans=0;
        for(i=1;i<=n;i++)
        {
            x= (a[i]+1)/2;
           // cout<<x<<endl;
            if(k-x>=0)
                {

                    k=k-x;
                    a[i]-=x;
                    ans++;
                }
            else break;
        }
       // cout<<k<<endl;
       int suc= ans;
       int cnt=0;
       int fails= n-ans;
       for(i=1;i<=suc;i++)
       {
            if(k-a[i]>=0)
                {
                    cnt++;
                    k=k-a[i];
                }
            else break;
       }

    cout<<fails<<" "<<cnt<<endl;
return 0;
}
